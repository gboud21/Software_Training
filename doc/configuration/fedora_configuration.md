# Installing Software

# Application Installations
## VS Code
This method enables automatic updates by importing the Microsoft GPG key and creating a repository file. 

1. Import GPG Key
    - sudo rpm --import https://packages.microsoft.com/keys/microsoft.asc
1. Add Repo: Create /etc/yum.repos.d/vscode.repo with Microsoft's repository details.
    - sudo sh -c 'echo -e "[code]\nname=Visual Studio Code\nbaseurl=https://packages.microsoft.com/yumrepos/vscode\nenabled=1\nautorefresh=1\ntype=rpm-md\ngpgcheck=1\ngpgkey=https://packages.microsoft.com/keys/microsoft.asc" > /etc/yum.repos.d/vscode.repo'
1. Install: Execute the following command:
    - sudo dnf check-update
    - sudo dnf install code