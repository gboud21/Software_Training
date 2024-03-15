# SRS Structure
This document aims to provide high-level guidance on how to structure a Software Requirements Specification (SRS).

# Introduction
The overal purpose of this section is to set the expectations of what is to come in the document.

## Purpose
-Should provide a high-level summary of the application. 
    -What is the problem it is trying to solve/Why was it developed? 
    -How is it intended to be used?
    -What is the intended outcome?

### Intended Audiance
-Define who is intended to be reading this document. (ie engineers, testers, leadership, buisness)

### Intended Understanding
-Define how the SRS is meant to be used

### Product Scope
-More specific information on the benifits, objectives and goals of the product. Specifically focus on the buisness goals.

# Overal Description
-This section focuses on providing a more technical description of the product that is being built. The goals of this section is to align the team on the product.
-It should talk about whether this is a new product, is it intended to integrate with existing product or add on to a different product?

## User needs
-This section focuses on the people actually using the product and detailing what their actual needs are to help inform the rest of the SRS.

## Assumptions and Dependencies
-This section should layout the Technical Assumptions being made going into the development of the CSCI. For example any technologies being used that are critical to its creation (ie frameworks)
-It should also detail any existing products/development that will be leveraged for the development of this CSCI.

# System Features and Requirements
-This section gets into the nitty-gritty of the CSCI and is where the actual technical functionality of the CSCI is flushed out. When creating requirements the goal should always be to include as much detail as possible. Including thedetails up-front forces the engineer to put real thought into how the CSCI should function within its environment andwhat are the critical factors to consider when progressing into the design of the CSCI. Providing ample detail alsodefines the criteria that the CSCI will be tested against which will influence the decisions being made during thedesign and implementation of the CSCI.

## Functional Requirements
-This section provides the details on the functionality of your CSCI
-Common questions to ask when writting these requirements
    -Does this add to my tool's functionality?
    -What function does this provide
-May also have requirements related to the interactions with external systems

## External Interface Requirements
-This section provides the details on how the CSCI will interface with other components
-The types of interfaces to consider are:
    -User
    -Hardware
    -Software
    -Communications

## System Features
-This section details features that are required in order for the system to function

## Nonfunctional Requirements
-This section focuses on requirements that ensure the product works as it is expected to
-For example
    -Performance Requirements
    -Safety Requirements
    -Security Requirements
    -Usability Requirements
    -Scalability Requirements

# Definitions and Acronyms
-Some templates recommend including this section under the Introduction Section; however, placing this section at the end of the document has the benefit of being able to easily find the section by simply scrolling to the end of the document. This idea is similar to how the majority of books will place the glossary or index at the end of the book as opposed to forcing the reader to search through the middle of the first chapter for the information. 