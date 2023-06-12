/* main.c
 *
 * Copyright 2023 Lucien GHEERBRANT, Yannick HU
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "environnement.h"
#include "challenge.h"

char* dataName(int n);
char* outputName(int n);

int main (int argc, char *argv[]) {
    environnement_st *env;
    env = (environnement_st*) malloc(sizeof(environnement_st));
    char nomData[] = "data/grnn.txt";
    char nomOutput[] = "output/res_n.txt";

    int i = atoi(argv[1]);

    strcpy(nomData, dataName(i));
    strcpy(nomOutput, outputName(i));
    printf("%s\n", nomData);
    printf("%s\n", nomOutput);

    initEnv(env, nomData);
   // printEnv(env);
    algo2(env);


    writeEnv(nomOutput, env, i);

    return 0;
}

char* dataName(int instance) {
    char* filePath = (char*) malloc(sizeof("data/grnn.txt"));

    sprintf(filePath, "data/gr%d.txt", instance); // Format the file path string

    return filePath;
}

char* outputName(int instance) {
    char* filePath = (char*) malloc(sizeof("output/res_n.txt"));

    sprintf(filePath, "output/res_%d.txt", instance); // Format the file path string

    return filePath;
}

