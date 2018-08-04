/*
    Breakout - Precompiler Definitions
    Copyright (C) 2018  Patrick Jakobsen
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.
    
    You should have received a copy of the GNU Affero General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DEFS_H_
#define DEFS_H_

//Error codes.
#define ERRORCODE_SDL 1
#define ERRORCODE_MEMORY 2

//Window properties.
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800

//Gameloop properties.
#define TICKRATE 25
#define TICKSPERFRAME (1000/TICKRATE)
#define MAXFRAMESKIP 2

#endif // DEFS_H_
