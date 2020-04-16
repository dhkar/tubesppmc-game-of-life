# tubesppmc-game-of-life
Code Repository for Conway's Game of Life by Kelompok 3 Romb. A Tugas Besar PPMC EL2208

Nama Kelompok :
1. Sabrina Adeline (13218014)
2. Muhammad Adnan (13218019) 
3. Melia Fatimah (13218020)
4. Andhika Rahadian (13218030)

Nama Asisten : Arief Hirmanto (13217076)

## Selayang Pandang Tentang Repo Ini
Repository ini memiliki 4 branch yang berada di belakang master:  
1. convertseedtoarray -> fitur mengubah seed file menjadi seed array untuk diproses lebih lanjut  
   Dikerjakan oleh Andhika Rahadian (13218030)  
2. function-tick -> fitur untuk menerima seed array dan melakukan iterasi sekali (fitur tick)  
   Dikerjakan oleh Melia Fatimah (13218020)  
3. Animate -> fitur untuk menampilkan seed array yang diiterasi sebanyak n kali dengan delay tertentu (fitur animate)  
   Dikerjakan oleh Muhammad Adnan (13218019)  
4. display -> fitur untuk menampilkan user interface dari game of life, dan algoritma program utama  
   Dikerjakan oleh Sabrina Adeline (13218014)  

Program utama diwakili oleh file bernama main.c, sementara fungsi pendukungnya diwakili oleh file header
(yang berisi fungsi fungsi) bernama game_of_life_lib.h dan display.h  

Adapun fungsi fungsi yang ada dalam game_of_life_lib.h adalah :  
1. getSeedData()
2. tick()
3. Animate()
4. delay()
5. destroyArray()

Sementara untuk fungsi fungsi yang ada di display.h adalah:

1. displaySeed()
2. displayMenu()
3. displayInterface()

Penjelasan fungsi (initial state dan final statenya) sudah ada didalam file header.  
