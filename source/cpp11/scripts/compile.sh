#!/bin/bash

set -e

CMAKE_EXE=/usr/bin/cmake
CURRENT_DIR=$(dirname "${0}")
BUILD_DIR=${CURRENT_DIR}/../build/
SOURCE_DIR=${CURRENT_DIR}/../

# --- Command Parameters
SHOULD_HELP=0
SHOULD_CLEAN=0
SHOULD_DEBUG=0

# --- Script Returns
RETURN_SUCCESS=0
RETURN_UNKNOWN_RETURN=1
RETURN_ARGUMENT_INIT_ERROR=2
RETURN_CMAKE_NOT_FOUND=3

# --- Prints a spacer for terminal output
function printSpacer {
    echo "================================================================"
}

# --- Prints the formated data for a parameter
function printParameter {
    echo "    ${1}"
    echo "        ${2}"
}

# --- Prints the help text for the script
function printHelp {
    printSpacer
    echo "Script: compile.sh"
    echo "Parameters:"
    printParameter "-h --help:" "Prints the help Script"
    printParameter "-c --clean" "Deletes the binaries from the previous build"
    printParameter "-d --debug" "Prints Debug Statements"
    printSpacer
}

# --- Prints the debug message to the terminal
function printDebug {
    if [ ${SHOULD_DEBUG} -eq 1 ]; then
        echo "${1}"
    fi
}
# --- Prints the output message to the terminal and exits the script
function exitScript {
    printSpacer
    printDebug "exitScript ${1}"
    case "${1}" in
    ${RETURN_SUCCESS})
        echo "Script Completed Successfully"
        ;;
    ${RETURN_UNKNOWN_RETURN})
        echo "Error: INVALID Return Type"
        ;;
    ${RETURN_ARGUMENT_INIT_ERROR})
        echo "Failed to initialize script parameters"
        ;;
    ${RETURN_CMAKE_NOT_FOUND})
        echo "File not found: ${CMAKE_EXE}"
        ;;
    *)
        printReturn ${RETURN_UNKNOWN_RETURN}
        ;;
    esac

    printSpacer
    exit ${1}
}

# --- Executes CMake to generate the Makefiles
function generateCMake {
    printDebug "generateCMake"

    if [ ! -f "${CMAKE_EXE}" ]; then
        exitScript ${RETURN_CMAKE_NOT_FOUND}
    fi

    # --- Execute command to generate Makefiles
    ${CMAKE_EXE} -S ${SOURCE_DIR} -B ${BUILD_DIR}
}

# --- Calls make to build the code
function build {
    printDebug "build"

    generateCMake

    # --- Execute command to build binaries
    ${CMAKE_EXE} --build ${BUILD_DIR}
}

# --- Cleans the source code
function clean {
    printDebug "Cleaning"

    if [ ! -f "${CMAKE_EXE}" ]; then
        exitScript ${RETURN_CMAKE_NOT_FOUND}
    fi

    # Execute command to clean build directory
    ${CMAKE_EXE} --build ${BUILD_DIR} --target clean

    if [ $? -ne 0 ]; then
        rm -rf ${BUILD_DIR}
    fi
}

# --- Main Script Execution
function main {
    printDebug "MAIN"
    if [ ${SHOULD_HELP} -eq 1 ]; then
        printHelp
    else
        if [ ${SHOULD_CLEAN} -eq 1 ]; then
            clean
        fi

        build
    fi

    exitScript ${RETURN_SUCCESS}
}

# --- Processes any script parameters
if [ $# -gt 0 ]; then
    VALID_ARGS=$(getopt -o cdh --long clean,debug,help -- "$@")

    if [[ $? -ne 0 ]]; then
        exitScript ${RETURN_ARGUMENT_INIT_ERROR}
    fi

    eval set -- "${VALID_ARGS}"

    while [ : ]; do
        case "${1}" in
        -c | --clean)
            SHOULD_CLEAN=1
            shift
            ;;
        -d | --debug)
            SHOULD_DEBUG=1
            shift
            ;;
        -h | --help)
            SHOULD_HELP=1
            shift
            ;;
        --)
            shift
            break
            ;;
        esac
    done
fi

# --- Execute the script
main
