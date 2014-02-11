max v2;#N vpatcher 577 44 1278 838;#P window setfont "Sans Serif" 9.;#P hidden newex 345 457 53 196617 r decoder;#N vpatcher 10 59 610 459;#P outlet 82 152 15 0;#P inlet 81 62 15 0;#P connect 0 0 1 0;#P pop;#P newobj 348 422 49 196617 p z-verb;#N vpatcher 10 59 610 459;#P outlet 82 152 15 0;#P inlet 81 62 15 0;#P connect 0 0 1 0;#P pop;#P newobj 331 392 50 196617 p y-verb;#N vpatcher 10 59 610 459;#P outlet 82 152 15 0;#P inlet 81 62 15 0;#P connect 0 0 1 0;#P pop;#P newobj 313 359 50 196617 p x-verb;#P newex 156 304 47 196617 *~ 360.;#P newex 156 282 64 196617 phasor~ 0.1;#P toggle 316 573 15 0;#P newex 16 598 284 196617 dac~ 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16;#P comment 335 573 100 196617 DSP on/off;#P window setfont "Sans Serif" 12.;#P comment 16 95 486 196620 An example of 3rd order encoding and decoding for 16+ loudspeakers;#P window setfont "Sans Serif" 9.;#P comment 16 62 300 196617 www.grahamwakefield.net;#P comment 16 50 300 196617 Graham Wakefield \, 2006;#P newex 563 65 108 196617 ambi.conventions.help;#P window setfont "Sans Serif" 20.;#P comment 16 21 301 196628 Ambisonics at 3rd order;#P window setfont "Sans Serif" 9.;#P window linecount 4;#P comment 383 23 300 196617 Inspired by work on a C++ implementation by Jorge Castellanos \, Florian Hollerweger and Graham Wakefield \, using the CSL framework developed at MAT/CREATE \, UCSB (www.create.ucsb.edu/CSL);#P window linecount 1;#P hidden newex 592 373 48 196617 loadbang;#P hidden newex 525 477 75 196617 loadmess 0.75;#P hidden newex 460 477 60 196617 loadmess 1;#P flonum 521 502 35 9 0. 1. 3 3 0 0 0 221 221 221 222 222 222 0 0 0;#P flonum 470 502 35 9 0. 0 1 3 0 0 0 221 221 221 222 222 222 0 0 0;#P message 521 524 50 196617 width \$1;#P message 470 525 43 196617 gain \$1;#P newex 16 283 34 196617 pink~;#P newex 580 556 68 196617 send decoder;#P window linecount 4;#P message 466 413 106 196617 speaker 12 -45 -45 \, speaker 13 45 -45 \, speaker 14 135 -45 \, speaker 15 -135 -45;#P message 466 355 101 196617 speaker 8 -45 45 \, speaker 9 45 45 \, speaker 10 135 45 \, speaker 11 -135 45;#P window linecount 3;#P comment 476 211 139 196617 Speakers 12-15 are a ring of 4 below the listener \, specified in degrees;#P comment 476 172 139 196617 Speakers 8-11 are a ring of 4 above the listener \, specified in degrees;#P window linecount 2;#P comment 476 144 140 196617 Speakers 0-7 are a horizontal ring of 8 \, specified in radians;#P window linecount 8;#P message 466 250 162 196617 speaker_radians 0 -0.392699 0. \, speaker_radians 1 0.392699 0. \, speaker_radians 2 1.178097 0. \, speaker_radians 3 1.963495 0. \, speaker_radians 4 2.748893 0. \, speaker_radians 5 3.534292 0. \, speaker_radians 6 4.31969 0. \, speaker_radians 7 5.105088 0.;#P user meter~ 294 511 307 584 50 0 168 0 103 103 103 255 153 0 255 0 0 217 217 0 153 186 0 12 3 3 3 3;#P user meter~ 276 511 289 584 50 0 168 0 103 103 103 255 153 0 255 0 0 217 217 0 153 186 0 12 3 3 3 3;#P user meter~ 258 511 271 584 50 0 168 0 103 103 103 255 153 0 255 0 0 217 217 0 153 186 0 12 3 3 3 3;#P user meter~ 240 511 253 584 50 0 168 0 103 103 103 255 153 0 255 0 0 217 217 0 153 186 0 12 3 3 3 3;#P user meter~ 223 511 236 584 50 0 168 0 103 103 103 255 153 0 255 0 0 217 217 0 153 186 0 12 3 3 3 3;#P user meter~ 205 511 218 584 50 0 168 0 103 103 103 255 153 0 255 0 0 217 217 0 153 186 0 12 3 3 3 3;#P user meter~ 187 511 200 584 50 0 168 0 103 103 103 255 153 0 255 0 0 217 217 0 153 186 0 12 3 3 3 3;#P user meter~ 169 511 182 584 50 0 168 0 103 103 103 255 153 0 255 0 0 217 217 0 153 186 0 12 3 3 3 3;#P user meter~ 150 511 163 584 50 0 168 0 103 103 103 255 153 0 255 0 0 217 217 0 153 186 0 12 3 3 3 3;#P user meter~ 132 511 145 584 50 0 168 0 103 103 103 255 153 0 255 0 0 217 217 0 153 186 0 12 3 3 3 3;#P user meter~ 114 511 127 584 50 0 168 0 103 103 103 255 153 0 255 0 0 217 217 0 153 186 0 12 3 3 3 3;#P user meter~ 96 511 109 584 50 0 168 0 103 103 103 255 153 0 255 0 0 217 217 0 153 186 0 12 3 3 3 3;#P user meter~ 79 511 92 584 50 0 168 0 103 103 103 255 153 0 255 0 0 217 217 0 153 186 0 12 3 3 3 3;#P user meter~ 61 511 74 584 50 0 168 0 103 103 103 255 153 0 255 0 0 217 217 0 153 186 0 12 3 3 3 3;#P user meter~ 43 511 56 584 50 0 168 0 103 103 103 255 153 0 255 0 0 217 217 0 153 186 0 12 3 3 3 3;#P user meter~ 25 511 38 584 50 0 168 0 103 103 103 255 153 0 255 0 0 217 217 0 153 186 0 12 3 3 3 3;#P window linecount 1;#P newex 16 481 284 196617 ambi.decode~ 3d 3rd 16;#P newex 16 325 291 196617 ambi.encode~ 3d 3rd degrees;#P comment 467 129 161 196617 A typical speaker layout:;#P window setfont "Sans Serif" 18.;#P comment 20 451 308 196626 W X Y U V P Q Z S T R N O L M K;#P user panel 14 344 389 136;#X brgb 208 228 254;#X frgb 84 172 230;#X border 2;#X rounded 0;#X shadow 0;#X done;#P background;#P connect 28 0 3 0;#P connect 3 0 4 0;#P hidden fasten 50 0 4 0 350 476 21 476;#P connect 4 0 43 0;#P fasten 44 0 43 0 321 593 21 593;#P connect 4 0 5 0;#P connect 3 1 4 1;#P fasten 47 0 4 1 318 381 39 381;#P lcolor 15;#P connect 4 1 43 1;#P connect 4 1 6 0;#P connect 3 2 4 2;#P fasten 48 0 4 2 336 411 57 411;#P lcolor 15;#P connect 4 2 43 2;#P connect 4 2 7 0;#P connect 3 3 4 3;#P connect 4 3 43 3;#P connect 4 3 8 0;#P connect 3 4 4 4;#P connect 4 4 43 4;#P connect 4 4 9 0;#P connect 3 5 4 5;#P connect 4 5 43 5;#P connect 4 5 10 0;#P connect 3 6 4 6;#P connect 4 6 43 6;#P connect 4 6 11 0;#P connect 3 7 4 7;#P fasten 49 0 4 7 353 444 147 444;#P lcolor 15;#P connect 4 7 43 7;#P connect 4 7 12 0;#P connect 45 0 46 0;#P connect 46 0 3 1;#P connect 3 8 4 8;#P connect 4 8 43 8;#P connect 4 8 13 0;#P connect 3 9 4 9;#P connect 4 9 43 9;#P connect 4 9 14 0;#P connect 3 10 4 10;#P connect 4 10 43 10;#P connect 4 10 15 0;#P connect 3 11 4 11;#P connect 4 11 43 11;#P connect 4 11 16 0;#P connect 3 12 4 12;#P connect 4 12 43 12;#P connect 4 12 17 0;#P connect 3 13 4 13;#P connect 4 13 43 13;#P connect 4 13 18 0;#P connect 3 14 4 14;#P connect 4 14 43 14;#P connect 4 14 19 0;#P connect 3 15 4 15;#P connect 4 15 43 15;#P connect 4 15 20 0;#P fasten 3 1 47 0 39 351 318 351;#P lcolor 15;#P fasten 3 2 48 0 57 388 336 388;#P lcolor 15;#P fasten 3 7 49 0 147 419 353 419;#P lcolor 15;#P hidden connect 35 0 21 0;#P hidden connect 35 0 25 0;#P hidden connect 35 0 26 0;#P hidden connect 33 0 31 0;#P connect 31 0 29 0;#P hidden connect 34 0 32 0;#P connect 32 0 30 0;#P fasten 25 0 27 0 471 409 585 409;#P fasten 21 0 27 0 471 351 585 351;#P fasten 26 0 27 0 471 467 585 467;#P fasten 29 0 27 0 475 548 585 548;#P fasten 30 0 27 0 526 548 585 548;#P pop;