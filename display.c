/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
*   MODUL 9 – TUGAS BESAR
*   Kelompok : 3
*   Rombongan : A
*   Hari dan Tanggal : Jumat, 10 April 2020
*   Asisten (NIM) : Arief Hirmanto (13217076)
*   Nama File : display.c
*   Deskripsi : fungsi displaySeed, displayInterface, dan displayMenu
*   Catatan : memperbaiki ketiga fungsi, masih terdapat bug pada case, masih ada beberapa testcase yang salah jika input saat quit
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **displaySeed(char **seedData, int *x_dim, int *y_dim){
    int i;
    int j;
    for(i=0; i<=y_dim; i++){
        for(j=0; j<=x_dim; j++){
            printf("%c ", seedData[i][j]);
        }
        printf("\n");
    }
}

int displayMenu(){
    int pilihan;
    printf("\n\nPilihan menu: \n");
    printf("1. Animate\n");
    printf("2. Tick\n");
    printf("3. Quit\n");
    printf("Masukkan menu yang dipilih : ");
    scanf("%d", &pilihan);
    return pilihan;
}

void displayInterface(){
    /*printf("\n====================================================\n");
    printf("\n---------------------Welcome to---------------------\n");
    printf("\n--------------------Game of Life--------------------\n");
    printf("\n====================================================\n");*/
    printf(":::       ::: :::::::::: :::         ::::::::   ::::::::  ::::    ::::  ::::::::::   :::::::::::  ::::::::\n");
    printf(":+:       :+: :+:        :+:        :+:    :+: :+:    :+: +:+:+: :+:+:+ :+:              :+:     :+:    :+:\n");
    printf("+:+       +:+ +:+        +:+        +:+        +:+    +:+ +:+ +:+:+ +:+ +:+              +:+     +:+    +:+\n");
    printf("+#+  +:+  +#+ +#++:++#   +#+        +#+        +#+    +:+ +#+  +:+  +#+ +#++:++#         +#+     +#+    +:+\n");
    printf("+#+ +#+#+ +#+ +#+        +#+        +#+        +#+    +#+ +#+       +#+ +#+              +#+     +#+    +#+\n");
    printf(" #+#+# #+#+#  #+#        #+#        #+#    #+# #+#    #+# #+#       #+# #+#              #+#     #+#    #+#\n");
    printf("  ###   ###   ########## ##########  ########   ########  ###       ### ##########       ###      ######## \n\n");

    printf(" ::::::::   ::::::::  ::::    ::: :::       :::     :::     :::   ::: :::  ::::::::      ::::::::       :::       :::   :::   ::::::::::    ::::::::   ::::::::::    :::        :::::::::::  ::::::::::  ::::::::::\n");
    printf(":+:    :+: :+:    :+: :+:+:   :+: :+:       :+:   :+: :+:   :+:   :+: :+  :+:    :+:    :+:    :+:    :+: :+:    :+:+: :+:+:  :+:          :+:    :+:  :+:           :+:            :+:      :+:         :+:\n");
    printf("+:+        +:+    +:+ :+:+:+  +:+ +:+       +:+  +:+   +:+   +:+ +:+      +:+           +:+          +:+   +:+  +:+ +:+:+ +:+ +:+          +:+    +:+  +:+           +:+            +:+      +:+         +:+\n");
    printf("+#+        +#+    +:+ +#+ +:+ +#+ +#+  +:+  +#+ +#++:++#++:   +#++:       +#++:++#++    :#:         +#++:++#++: +#+  +:+  +#+ +#++:++#     +#+    +:+  :#::+::#      +#+            +#+      :#::+::#    +#++:++#\n");
    printf("+#+        +#+    +#+ +#+  +#+#+# +#+ +#+#+ +#+ +#+     +#+    +#+               +#+    +#+   +#+#  +#+     +#+ +#+       +#+ +#+          +#+    +#+  +#+           +#+            +#+      +#+         +#+\n");
    printf("#+#    #+# #+#    #+# #+#   #+#+#  #+#+# #+#+#  #+#     #+#    #+#        #+#    #+#    #+#    #+#  #+#     #+# #+#       #+# #+#          #+#    #+#  #+#           #+#            #+#      #+#         #+#\n");
    printf(" ########   ########  ###    ####   ###   ###   ###     ###    ###         ########      ########   ###     ### ###       ### ##########    ########   ###           ########## ###########  ###         ##########\n");
}
