/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2012 - Hans-Kristian Arntzen
 *  Copyright (C) 2011-2012 - Daniel De Matteis
 * 
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

/* RetroArch Bifrost: 
 * A burning rainbow bridge that reaches between Java (the world) 
 * and C/C++, the realm of the gods */

#include <stdio.h>
#include <jni.h>
#include "../boolean.h"

#include "../console/rarch_console_rom_ext.h"
#include "../general.h"

JNIEXPORT void JNICALL Java_com_retroarch_RRuntime_load_game
   (JNIEnv *env, jclass class, jstring j_path, jint j_extract_zip_mode)
{
   jboolean is_copy = false;
   const char * game_path = (*env)->GetStringUTFChars(env, j_path, &is_copy);

   rarch_console_load_game_wrap(game_path, 0, 0);

   (*env)->ReleaseStringUTFChars(env, j_path, game_path);
}

JNIEXPORT jboolean JNICALL Java_com_retroarch_RRuntime_run_frame
   (JNIEnv *env, jclass class)
{
   return rarch_main_iterate();
}
