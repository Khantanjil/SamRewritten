#pragma once

class MySteam;
class MainPickerWindow;
class MySteamClient;
class PerfMon;

// Reason for the globals is that it's easier to access them in GTK callbacks
// All those variables are initialised in main.cpp

/**
 * A custom Steam Client interface, because the Steamworks lib won't let me get 
 * the SteamClient() accessor before a SteamAPI_Init(). It replaces the accessor
 * without having to initialize the whole SDK.
 */
extern MySteamClient *g_steamclient;

/**
 * g_steam is the backend of all of this, the M of the MVC. It will analyse the
 * steam folder and give data about it: games owned, icons, etc.
 */
extern MySteam *g_steam;

/**
 * g_main_gui is the main application window. If you can read this, it is very
 * glitchy, freezes instead of showing the loading widget, but still looks
 * half-decent. It's the V of the MVC.
 */
extern MainPickerWindow *g_main_gui;

/**
 * The absolute path to the cache folder. It's global, because everyone will
 * need to write or read into this folder at some point. 
 * XDG Base Directory Specification is followed:
 * If present, this variable uses XDG_CACHE_HOME and takes the value
 *      $XDG_CACHE_HOME/SamRewritten
 * Otherwise, this variable properly defaults to
 *      ~/.cache/SamRewritten
 */
extern char *g_cache_folder;

/**
 * The absolute path to the runtime folder. It's global, because everyone will
 * need to write or read into this folder at some point. It's used for storing
 * sockets used by the program.
 * XDG Base Directory Specification is followed:
 * If present, this variable uses XDG_RUNTIME_DIR and takes the value
 *      $XDG_RUNTIME_DIR/SamRewritten
 * Warnings are properly issued if it is not set, but  still defaults to the
 * cache folder for simplicity
 */
extern char *g_runtime_folder;

/**
 * A basic performance monitor
 */
extern PerfMon *g_perfmon;
