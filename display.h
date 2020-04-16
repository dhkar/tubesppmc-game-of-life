/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
*   MODUL 9 - TUGAS BESAR
*   Kelompok : 3
*   Rombongan : A
*   Hari dan Tanggal : Jumat, 10 April 2020
*   Asisten (NIM) : Arief Hirmanto (13217076)
*   Nama File : display.h
*   Deskripsi : file library untuk display
*   Catatan : memperbaiki ketiga fungsi display + finishing 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef DISPLAY_H
#define DISPLAY_H

/* Fungsi displaySeed digunakan untuk mencetak array seed yang sudah terproses
    I.S. terdapat array seed 2D yang sudah melalui proses animate atau tick
    F.S. array 2D tersebut dicetak sehingga terlihat dalam cmd
*/
void displaySeed(char **seedData, int *x_dim, int *y_dim)
{
    int i;
    int j;
    for(i=0; i< *y_dim; i++){
        for(j=0; j< *x_dim; j++){
            printf("%c ", seedData[i][j]);
        }
        printf("\n");
    }
}

/* Fungsi displayMenu digunakan untuk mencetak menu pada user
    I.S. setelah program meminta user memasukkan nama file seed
    F.S. user memasukkan input pilihan pada display menu dan program menjalankan fungsi sesuai pilihan user
*/
int displayMenu()
{
    int pilihan;
    printf("\n\nPilihan menu: \n");
    printf("1. Animate\n");
    printf("2. Tick\n");
    printf("3. Quit\n");
    printf("Masukkan menu yang dipilih : ");
    scanf("%d", &pilihan);
    return pilihan;
}

/* Fungsi displayInterface digunakan untuk mencetak judul program atau sebagai header game
    I.S. saat program pertama kali dijalankan
    F.S. judul program akan dicetak pada terminal selama beberapa detik kemudian program meminta inputan file seed
*/
void displayInterface()
{
    printf(":::       ::: :::::::::: :::         ::::::::   ::::::::  ::::    ::::  ::::::::::   :::::::::::  ::::::::\n");
    printf(":+:       :+: :+:        :+:        :+:    :+: :+:    :+: +:+:+: :+:+:+ :+:              :+:     :+:    :+:\n");
    printf("+:+       +:+ +:+        +:+        +:+        +:+    +:+ +:+ +:+:+ +:+ +:+              +:+     +:+    +:+\n");
    printf("+#+  +:+  +#+ +#++:++#   +#+        +#+        +#+    +:+ +#+  +:+  +#+ +#++:++#         +#+     +#+    +:+\n");
    printf("+#+ +#+#+ +#+ +#+        +#+        +#+        +#+    +#+ +#+       +#+ +#+              +#+     +#+    +#+\n");
    printf(" #+#+# #+#+#  #+#        #+#        #+#    #+# #+#    #+# #+#       #+# #+#              #+#     #+#    #+#\n");
    printf("  ###   ###   ########## ##########  ########   ########  ###       ### ##########       ###      ######## \n\n");

    printf(" ::::::::   ::::::::  ::::    ::: :::       :::     :::     :::   ::: :::  :::::::: \n");
    printf(":+:    :+: :+:    :+: :+:+:   :+: :+:       :+:   :+: :+:   :+:   :+: :+  :+:    :+: \n");
    printf("+:+        +:+    +:+ :+:+:+  +:+ +:+       +:+  +:+   +:+   +:+ +:+      +:+        \n");
    printf("+#+        +#+    +:+ +#+ +:+ +#+ +#+  +:+  +#+ +#++:++#++:   +#++:       +#++:++#++ \n");
    printf("+#+        +#+    +#+ +#+  +#+#+# +#+ +#+#+ +#+ +#+     +#+    +#+               +#+ \n");
    printf("#+#    #+# #+#    #+# #+#   #+#+#  #+#+# #+#+#  #+#     #+#    #+#        #+#    #+# \n");
    printf(" ########   ########  ###    ####   ###   ###   ###     ###    ###         ########  \n");

    printf(" ::::::::      :::     ::::    ::::  ::::::::::   ::::::::  ::::::::::  :::        ::::::::::: :::::::::: :::::::::: \n");
    printf(":+:    :+:   :+: :+:   +:+:+: :+:+:+ :+:         :+:    :+: :+:         :+:            :+:     :+:        :+:        \n");
    printf("+:+         +:+   +:+  +:+ +:+:+ +:+ +:+         +:+    +:+ +:+         +:+            +:+     +:+        +:+        \n");
    printf(":#:        +#++:++#++: +#+  +:+  +#+ +#++:++#    +#+    +:+ :#::+::#    +#+            +#+     :#::+::#   +#++:++#   \n");
    printf("+#+   +#+# +#+     +#+ +#+       +#+ +#+         +#+    +#+ +#+         +#+            +#+     +#+        +#+        \n");
    printf("#+#    #+# #+#     #+# #+#       #+# #+#         #+#    #+# #+#         #+#            #+#     #+#        #+#        \n");
    printf(" ########  ###     ### ###       ### ##########   ########  ###         ########## ########### ###        ########## \n");

    int ms =  3000;
    clock_t start_time = clock();
    while (clock() < start_time + ms);

    system("@cls||clear");
}

#endif
