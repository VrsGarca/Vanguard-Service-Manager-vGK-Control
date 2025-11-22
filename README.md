# Vanguard Service Monitor

A Windows utility package for managing the startup behavior of Riot Vanguard's anti-cheat service.

## Overview

This project consists of two command-line tools designed to help users manage the Riot Vanguard anti-cheat driver (`vgk` service) on Windows systems:

- **vgkChecker**: Monitors the current status of the Vanguard service
- **noVanguard**: Changes Vanguard's automatic startup behavior with a single click

## Features

- **Service Status Monitoring**: Check if Vanguard is currently running
- **Auto-start Detection**: See if Vanguard is configured to start automatically
- **Toggle Auto-start**: Enable or disable Vanguard's automatic startup
- **System Restart Integration**: Optionally restart your system to apply changes immediately
- **Colored Console Output**: Easy-to-read status messages with color-coded logging
- **Privilege Management**: Automatic elevation checks and privilege handling

## Use Case

Riot Vanguard runs at system startup and operates at the kernel level, which can:
- Impact system performance
- Conflict with certain software
- Run even when you're not playing Valorant or League of Legends

These tools give you control over when Vanguard runs, allowing you to:
- Disable auto-start when you don't need it
- Re-enable it easily before playing Riot games
- Avoid unnecessary system resource usage

## Requirements

- Windows operating system
- Administrator privileges
- Riot Vanguard installed (from Valorant or League of Legends)
- Visual Studio 2019 or later (for building from source)

## Installation

### Pre-built Binaries
1. Download the latest release from the [Releases](../../releases) page
2. Extract the archive
3. Run the desired tool as Administrator

### Building from Source
```bash
# Clone the repository
cd noVanguard

# Open the solution in Visual Studio
# Build the solution (Ctrl+Shift+B)
# Executables will be in the Debug/Release folder
```

## Usage

### vgkChecker

Simply run `vgkChecker.exe` as Administrator to check Vanguard's current status.

**Example Output:**
```
[notice] Vanguard driver is running, and is set to auto-start.
[notice] Press enter to close app.
```

### noVanguard

Run `noVanguard.exe` as Administrator to toggle Vanguard's auto-start setting.

**The tool automatically detects the current state and performs the opposite action:**

| Current State | Action |
|--------------|--------|
| Running + Auto-start ON | Disables auto-start |
| Stopped + Auto-start OFF | Enables auto-start |
| Running + Auto-start OFF | Enables auto-start |
| Stopped + Auto-start ON | Disables auto-start |

**Example Output:**
```
[notice] Made with <3 by rebn
[notice] Vanguard is currently running on this system, and is set to auto-start.
[notice] Attempting to disable auto-start for Vanguard.
[notice] Auto-start has been set to disabled state for Vanguard.
[notice] A system restart is required to append changes...
```

## ⚠️ Important Notes

- **Administrator Rights Required**: Both tools require elevation to modify Windows services
- **Restart May Be Needed**: Changes to a running service require a system restart to take effect
- **Kernel-level Service**: Vanguard operates at the kernel level, so service changes need careful handling

## Code Components

### Service Controller
- `find_manager()`: Opens the Windows Service Control Manager
- `get_vgk_status()`: Queries current service state
- `do_query_svc()`: Gets service configuration
- `config_vgk()`: Modifies service startup type
- `close_manager()`: Cleanup and resource release

### Utilities
- `is_process_elevated()`: Checks for administrator privileges
- `log_type()`: Color-coded console logging
- `elevate_privileges()`: Token privilege adjustment

## Contributing

Contributions are welcome! Please feel free to submit pull requests.

## isclaimer

This tool is provided for educational and convenience purposes only. Users are responsible for complying with Riot Games' Terms of Service and End User License Agreement.

## License

This project is licensed under the [MIT License](LICENSE).