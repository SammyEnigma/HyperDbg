/**
 * @file install.h
 * @author Sina Karvandi (sina@hyperdbg.org)
 * @brief Main interface to connect applications to driver headers
 * @details
 * @version 0.1
 * @date 2020-04-11
 *
 * @copyright This project is released under the GNU Public License v3.
 *
 */
#pragma once

//
// The following ifdef block is the standard way of creating macros which make
// exporting from a DLL simpler. All files within this DLL are compiled with the
// LIBHYPERDBG_EXPORTS symbol defined on the command line. This symbol should not
// be defined on any project that uses this DLL. This way any other project
// whose source files include this file see LIBHYPERDBG_API functions as being
// imported from a DLL, whereas this DLL sees symbols defined with this macro as
// being exported.
//

#ifdef LIBHYPERDBG_EXPORTS
#    define LIBHYPERDBG_API __declspec(dllexport)
#else
#    define LIBHYPERDBG_API __declspec(dllimport)
#endif

//////////////////////////////////////////////////
//					Installer                   //
//////////////////////////////////////////////////

#define DRIVER_FUNC_INSTALL 0x01
#define DRIVER_FUNC_STOP    0x02
#define DRIVER_FUNC_REMOVE  0x03

//////////////////////////////////////////////////
//					Functions                   //
//////////////////////////////////////////////////

BOOLEAN
InstallDriver(SC_HANDLE SchSCManager, LPCTSTR DriverName, LPCTSTR ServiceExe);

BOOLEAN
RemoveDriver(SC_HANDLE SchSCManager, LPCTSTR DriverName);

BOOLEAN
StartDriver(SC_HANDLE SchSCManager, LPCTSTR DriverName);

BOOLEAN
StopDriver(SC_HANDLE SchSCManager, LPCTSTR DriverName);

BOOLEAN
ManageDriver(_In_ LPCTSTR DriverName, _In_ LPCTSTR ServiceName, _In_ UINT16 Function);

BOOLEAN
SetupPathForFileName(const CHAR *                                  FileName,
                     _Inout_updates_bytes_all_(BufferLength) PCHAR FileLocation,
                     ULONG                                         BufferLength,
                     BOOLEAN                                       CheckFileExists);
