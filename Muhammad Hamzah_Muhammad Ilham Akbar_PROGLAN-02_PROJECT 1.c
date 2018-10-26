#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winnt.h>


/*
				NAMA KELOMPOK :
		Muhammad Hamzah / 1706043065
		Muhammad Ilham Akbar / 1706042970
		
Program ini adalah sebuah aplikasi perpustakaan tentang peminjaman dan pengembalian buku.
Program ini dapat menampilkan daftar buku yang tersedia dan daftar peminjam.
program ini menyimpan semua daftar dalam file txt yang telah terbuat secara otomatis oleh program ini.
Pade source code program ini terdapat scanf EOF yang berfungsi untuk melakukan scanf per baris sampai baris terakhir.
Pade source code program ini terdapat strcmp yang berfungsi untuk membandingkan antar string.
Pade source code program ini terdapat strcpy yang berfungsi untuk memasukkan data berupa string dari satu variabel ke variabel lain.
*/

void menu(); // modular untuk menmapilkan menu program
void pinjam(); //modular peminjam buku
void pengembalian(); //modular pengembalian buku yang dipinjam
void penambahan_buku(); //modular untuk penambahan buku dalam daftar informasi dan daftar buku yang tersedia untuk dipinjam
void hapus_buku(); //modular untuk menghapus buku dalam daftar informasi dan daftar buku yang tersedia untuk dipinjam
void informasi_peminjam (); //modular untuk menampilkan informasi peminjam buku 
void informasi_buku(); //modular untuk menampilkan daftar informasi buku dan daftar buku yang tersedia untuk dipinjam
void help(); //modular untuk menampilkan panduan penggunaan program
char kode[100]; //variabel kode buku
char kode2[100]; //variabel kode  buku untuk membandingkan
char nama1[100], nama2[100]; //variabel untuk menampung nama depan dan mana belakang
char tgl [100]; //variabel untuk menampung tanggal peminjaman
char bulan[100]; //variabel untuk menampung bulan peminjaman
char tahun[100]; //variabel untuk menampung tahun peminjaman
char npm [100]; //variabel untuk menampung NPM data diri perminjam
char buku1[100], buku2[100], buku3[100], buku4[100], buku5[100]; //variabel untuk menampung judul buku dalam 5 suku kata
char edisi[100]; //variabel untuk menampung edisi buku
char terbit[100]; //variabel untuk menmapung tahun terbit buku
char penulis1 [100], penulis2 [100], penulis3 [100]; //variabel untuk menampung nama penulis buku dalam 3 suku kata
int system();

void header ()
{
	printf ("");
	printf ("\t\t=======================================\n");
	printf ("\t\t           Selamat datang\n");
	printf ("\t\t       APLIKASI PERPUSTAKAAN\n");
	printf ("\t\t=======================================\n");
	
}

void header_menu()
{
	printf ("\t\t=======================================\n");
	printf ("\t\t|           PERPUSTAKAAN              |\n");        
	printf ("\t\t=======================================\n");
}

void peminjaman_header()
{
	printf ("\t\t=======================================\n");
	printf ("\t\t     	       Pinjam Buku\n");
	printf ("\t\t=======================================\n");
} 

void pengembalian_header()
{
	printf ("\t\t=======================================\n");
	printf ("\t\t  	     Pengembalian Buku\n");
	printf ("\t\t=======================================\n");
}

void penambahan_header()
{
	printf ("\t\t=======================================\n");
	printf ("\t\t            Penambahan Buku\n");
	printf ("\t\t=======================================\n");
} 

void hapus_buku_header()
{
	printf ("\t\t=======================================\n");
	printf ("\t\t  Hapus Buku dari Daftar Buku Tersedia\n");
	printf ("\t\t=======================================\n");
}

void daftar_peminjam_header()
{
	printf ("\t\t=======================================\n");
	printf ("\t\t         Daftar Peminjam Buku\n");
	printf ("\t\t=======================================\n");
} 

void daftar_buku_header()
{
	printf ("\t\t=======================================\n");
	printf ("\t\t           Daftar Buku Tersedia\n");
	printf ("\t\t=======================================\n");
} 

void help_header()
{
	printf ("\t\t=======================================\n");
	printf ("\t\t             Bantuan/Help\n");
	printf ("\t\t=======================================\n");
}

int main()
{
	header ();
	system ("pause");
	system ("cls");
	menu ();
}

void menu ()
{
	header_menu();
	printf("			        MENU\n");
	printf("		1. Peminjaman\n");
	printf("		2. Pengembalian Buku\n");
	printf("		3. Penambahan Buku Tersedia\n");
	printf("		4. Hapus Buku dari Daftar\n");
	printf("		5. Informasi Peminjam Buku\n");
	printf("		6. Informasi Buku Tersedia\n");
	printf("		7. Help (PERTAMA PAKAI? BACA DULU INI)\n");
	printf("		0. Keluar\n");
	printf("		   Silahkan masukkan angka pada menu tersebut : ");	
	
	switch (getch())//input menu yang diinginkan berdasarkan angka pada menu (switch berdasarkan getch)
	{
		case '1' :
			pinjam (); //memanggil modular pinjam
			break;
		case '2' :
			pengembalian (); //memanggil modular pengembalan
			break;
		case '3' :
			penambahan_buku(); //memanggil modular penambahan buku
			break;
		case '4' :
			hapus_buku(); //memanggil modular haus buku
			break;
		case '5' :
			informasi_peminjam (); //memanggil modular informasi peminjam buku
			break;
		case '6' :
		    informasi_buku(); //memanggil modular informasi buku
		    break;
		case '7' :
			help(); //memanggil fungsi help
			break;
		case '0' :
			exit(0); //keluar dari program
			break;
		default :
			printf("\n		Wrong input.\n		");
			system("pause");
			system("cls");
			menu();
	}
}

void pinjam()
{
	int ada;
	printf ("\n		");
	system ("pause");
	system ("cls");
	peminjaman_header();
	FILE *out=fopen("daftar_peminjam.txt","a"); //deklarisi pointer dari tipe file disertai dengan open file daftar_peminjam dengan akses mode a (menambah daftar)
	FILE *out1=fopen("daftar_buku.txt","r"); //deklarisi pointer dari tipe file disertai dengan open file daftar_buku dengan akses mode r (membaca isi file)
	FILE *out4=fopen("temp_buku_pinjam.txt","a"); //deklarisi pointer dari tipe file disertai dengan open file temp_buku_pinjam dengan akses mode a (menambah daftar)
	FILE *out3=fopen("temp_buku.txt", "w");//deklarisi pointer dari tipe file disertai dengan open file temp_buku dengan akses mode w (rewrite isi file)
	printf("\nKode Buku	: "); 
	scanf("%s", &kode2);
	while(fscanf(out1,"%s %s %s %s %s %s %s %s %s %s %s\n", buku1, buku2, buku3, buku4, buku5, edisi, penulis1, penulis2, penulis3, terbit, kode)!=EOF){
		if((strcmp(kode,kode2)==0)){
			ada = 1;
			printf("\nJudul		: %s %s %s %s %s\n", buku1, buku2, buku3, buku4, buku5);
        	printf("Edisi		: %s\n", edisi);
	    	printf("Penulis		: %s %s %s\n", penulis1, penulis2, penulis3);
	    	printf("Tahun Terbit	: %s\n", terbit);
	    	printf("Kode Buku	: %s\n\n", kode);
	    	fprintf(out4,"%s %s %s %s %s %s %s %s %s %s %s\n", buku1, buku2, buku3, buku4, buku5, edisi, penulis1, penulis2, penulis3, terbit, kode); //program melakukan print di file.txt berdasarkan pointer out4
		}
		else{
			fprintf(out3, "%s %s %s %s %s %s %s %s %s %s %s\n", buku1, buku2, buku3, buku4, buku5, edisi, penulis1, penulis2, penulis3, terbit, kode); //program melakukan print di file.txt berdasarkan pointer out4
		}
	}
	if(ada!=1){
		fclose(out); //menutup file.txt berdasarkan pointer out
		fclose(out1); //menutup file.txt berdasarkan pointer out1 
		fclose(out3); //menutup file.txt berdasarkan pointer out3
		fclose(out4); //menutup file.txt berdasarkan pointer out4
		printf("\nKode buku tidak ada.\n");
		printf("Apakah Anda masih ingin meminjam lagi [Y/N]? ");
		switch(getch()){
			case 'y' :
				printf("\n");
				pinjam();
			case'Y' :
				printf("\n");
				pinjam();
			case'n' :
				system("cls");
				menu();
			case'N' :
				system("cls");
				menu();
			default :
				printf("\n\n			Wrong input.");
				pinjam();
		}
	}
	fclose(out1); //menutup file.txt berdasarkan pointer out1
	fclose(out3); //menutup file.txt berdasarkan pointer out3
	printf("Memasukkan data diri\n");
	printf("(Input nama dalam 1 kata)\n");
	printf("Masukkan nama depan   : "); 
	scanf("%s", &nama1);
	printf("Masukkan nama belakang: "); 
	scanf("%s", &nama2);
	printf("Masukkan NPM/KTP      : "); 
	scanf("%s", &npm);
	printf("Tanggal Peminjaman (contoh: 15 februari 2018 ditulis 15 02 2018): \n"); 
	scanf("%s %s %s", &tgl, &bulan, &tahun);
	fprintf(out,"%s %s %s %s %s %s %s\n",nama1, nama2, npm, kode, tgl, bulan, tahun);
	out1=fopen("daftar_buku.txt","w"); //open file daftar_buku.txt dengan akses mode w (rewrite daftar)
	out3=fopen("temp_buku.txt", "r"); //open file temp_buku.txt dengan akses mode r (read daftar)
	while(fscanf(out3,"%s %s %s %s %s %s %s %s %s %s %s\n", buku1, buku2, buku3, buku4, buku5, edisi, penulis1, penulis2, penulis3, terbit, kode)!=EOF)
	{
		fprintf(out1,"%s %s %s %s %s %s %s %s %s %s %s\n", buku1, buku2, buku3, buku4, buku5, edisi, penulis1, penulis2, penulis3, terbit, kode); //program melakukan print di file.txt berdasarkan pointer out1
	}
	fclose(out1); //menutup file.txt berdasarkan pointer out1
	fclose(out3); //menutup file.txt berdasarkan pointer out3
	fclose(out4); //menutup file.txt berdasarkan pointer out4
	fclose(out); //menutup file.txt berdasarkan pointer out
	remove("temp_buku.txt"); //remove (hapus) file temp_buku.txt
	printf("Sukses menambah data \n");
	system ("pause");
	system ("cls");
	menu();
}

void pengembalian ()
{
	int ada = 0;
    FILE *out=fopen("daftar_peminjam.txt","r"),*out1=fopen("temp.txt","w");
    printf ("\n		");
	system ("pause");
	system ("cls");
	pengembalian_header();
	printf("\nMasukkan Kode Buku dengan BENAR : ");
	scanf("%s", &kode2 );
	while(fscanf(out,"%s %s %s %s %s %s %s \n",nama1,nama2,npm,kode,tgl,bulan,tahun)!=EOF)
	{
        if((strcmp(kode,kode2)==0))
        {
        	ada = 1;
        	printf("\nNama 			: %s %s\n",nama1,nama2);
        	printf("NPM/KTP 	    	: %s\n",npm);
	    	printf("Kode Buku 	    	: %s\n",kode);
	    	printf("Tgl Pinjam (DD-MM-YYYY)	: %s-%s-%s\n",tgl,bulan,tahun);
        }
        else
		{
        	fprintf(out1,"%s %s %s %s %s %s %s\n",nama1,nama2,npm,kode,tgl,bulan,tahun);
		}
    }
    fclose(out);
    fclose(out1);
    if (ada == 1)
    {
    	printf("\nApakah Anda yakin akan mengembalikan buku ini [Y/N]? ");
    	switch (getch())
    	{
    		case 'Y':
    		case 'y':
				out=fopen("daftar_peminjam.txt","w");
				out1=fopen("temp.txt","r+");
				while(fscanf(out1,"%s %s %s %s %s %s %s\n",nama1,nama2,npm,kode,tgl,bulan,tahun)!=EOF)
				{
			    	fprintf(out,"%s %s %s %s %s %s %s \n",nama1,nama2,npm,kode,tgl,bulan,tahun);
				}
				fclose(out);
				fclose(out1);
				remove("temp.txt");
				printf("\n\t\t\tReturn success!\n\n");
				system ("pause");
				system ("cls");
    			menu();
			case 'N':
			case 'n':
				system ("pause");
				system ("cls");
				menu();
		
			default :
				printf("\n\t\t\tWrong input!\n\t\t");
				pengembalian();	    		
		}
	}
	if (ada == 0)
    {
    	printf("\nKode ini tidak ada dalam peminjaman. Kembali ke MENU.\n");
	}
	remove("temp.txt");
    system("pause");
    system ("cls");
    menu();
}

void penambahan_buku ()
{
	int ada1=0;
	FILE *out=fopen("daftar_buku.txt","r");
	printf ("\n		");
	system ("pause");
	system ("cls");
	penambahan_header();
	printf("\nMasukkan Kode Buku dengan BENAR : ");
	scanf("%s", &kode2 );
	while(fscanf(out,"%s %s %s %s %s %s %s %s %s %s %s\n", buku1, buku2, buku3, buku4, buku5, edisi, penulis1, penulis2, penulis3, terbit, kode)!=EOF)
	{
        if((strcmp(kode,kode2)==0))
        {
        	fclose (out);
        	printf ("Maaf, kode buku telah digunakan\n");
        	printf("Apakah Anda masih ingin menambah buku lagi [Y/N]? ");
			switch(getch())
			{
				case 'y' :
					printf("\n");
					penambahan_buku();
				case'Y' :
					printf("\n");
					penambahan_buku();
				case'n' :
					system("cls");
					menu();
				case'N' :
					system("cls");
					menu();
				default :
					printf("\n\n			Wrong input.");
					penambahan_buku();
			}
        	
		}
        
    }
    fclose(out);
    out=fopen("daftar_buku.txt","a");
	printf ("\n(MASUKKAN JUDUL BUKU DALAM 5 KATA, NAMA PENULIS DALAM 3 KATA\n");
	printf("Apabila kurang dari itu, berikan tanda '-' untuk setiap kata\n");
	printf("Contoh	: (Penulis) Morris Mano\n");
	printf("	  ditulis : Morris Mano -\n");
	printf("	  (Judul) Fundamental of Physics\n");
	printf("	  ditulis : Fundamental of Physics - -\n\n");
	printf("Judul buku		: "); 
	scanf("%s %s %s %s %s", &buku1, &buku2, &buku3, &buku4, &buku5);
	printf("Edisi buku		: "); 
	scanf("%s", &edisi);
	printf("Penulis buku		: ");
	scanf ("%s %s %s", &penulis1, &penulis2, &penulis3);
	printf("Tahun terbit buku	: "); 
	scanf("%s", &terbit);
	strcpy(kode,kode2);
	printf("Kode Buku		: %s\n\n", kode); 
	fprintf(out,"%s %s %s %s %s %s %s %s %s %s %s\n",buku1, buku2, buku3, buku4, buku5, edisi, penulis1, penulis2, penulis3, terbit, kode);
	fclose(out);
	printf("Sukses menambah data \n");
	system ("pause");
	system ("cls");
	menu();
}

void hapus_buku()
{
	int ada2 = 0;
    FILE *out=fopen("daftar_buku.txt","r"),*out1=fopen("temp_buku.txt","w");
    printf ("\n		");
	system ("pause");
	system ("cls");
	hapus_buku_header();
	printf ("[HAPUS BUKU DARI DAFTAR]");
	printf ("\n(Masukkan KODE buku dengan BENAR)\n");
	printf("Masukkan Kode Buku : ");
	scanf("%s", &kode2 );
	while(fscanf(out,"%s %s %s %s %s %s %s %s %s %s %s\n",buku1, buku2, buku3, buku4, buku5, edisi, penulis1, penulis2, penulis3, terbit, kode)!=EOF)
	{
        if((strcmp(kode,kode2)==0))
        {
        	ada2 = 1;
        	printf("Judul Buku    : %s %s %s %s %s\n",buku1, buku2, buku3, buku4, buku5);
       		printf("Edisi         : %s\n", edisi);
       		printf("penulis       : %s %s %s\n", penulis1, penulis2, penulis3);
       		printf("Terbit        : %s\n", terbit);
       		printf("Kode Buku     : %s\n", kode);
        }
        else
		{
        	fprintf(out1,"%s %s %s %s %s %s %s %s %s %s %s\n",buku1, buku2, buku3, buku4, buku5, edisi, penulis1, penulis2, penulis3, terbit, kode);
		}
    }
    fclose(out);
    fclose(out1);
    if (ada2 == 1)
    {
    	printf("\n Apakah Anda yakin akan menghapus file ini [Y/N]? ");
    	switch (getch())
    	{
    		case 'Y' :
    		case 'y' :
				out=fopen("daftar_buku.txt","w");
				out1=fopen("temp_buku.txt","r+");
				while(fscanf(out1,"%s %s %s %s %s %s %s %s %s %s %s\n",buku1, buku2, buku3, buku4, buku5, edisi, penulis1, penulis2, penulis3, terbit, kode)!=EOF)
				{
			    	fprintf(out,"%s %s %s %s %s %s %s %s %s %s %s\n",buku1, buku2, buku3, buku4, buku5, edisi, penulis1, penulis2, penulis3, terbit, kode);
				}
				fclose(out);
				fclose(out1);
				remove("temp_buku.txt");
				printf("\n\t\t\tDelete success!");
				system ("pause");
				system ("cls");
    			menu();
			case 'N' :
			case 'n' :
				system ("pause");
				system ("cls");
				menu();
			default :
				printf("\n\t\t\tWrong input!\n");
				hapus_buku();	    		
		}	
	}
	if (ada2 == 0)
    {
    	printf("\nTidak ada kode ini di Daftar Buku Tersedia. Kembali ke MENU.\n");
	}
	remove("temp_buku.txt");
    system("pause");
    system ("cls");
    menu();
}

void informasi_peminjam ()
{
	FILE *out;
	out=fopen("daftar_peminjam.txt","r");
	printf ("\n		");
	system ("pause");
	system ("cls");
	daftar_peminjam_header();
        while(fscanf(out,"%s %s %s %s %s %s %s\n",nama1,nama2,npm,kode,tgl,bulan,tahun)!=EOF)
   		{
   			printf ("\n");
        	printf("Nama 			: %s %s\n",nama1,nama2);
       		printf("Kode Buku       	: %s\n",kode);
       		printf("NPM/KTP          	: %s\n",npm);
       		printf("Tgl pinjam (DD-MM-YYYY) : %s-%s-%s\n",tgl,bulan,tahun);
		}
	fclose(out);
	system ("pause");
	system ("cls");
	menu();
}

void informasi_buku()
{
	FILE *out;
	out=fopen("daftar_buku.txt","r");
	printf ("\n		");
	system ("pause");
	system ("cls");
	daftar_buku_header();
        while(fscanf(out,"%s %s %s %s %s %s %s %s %s %s %s\n",buku1, buku2, buku3, buku4, buku5, edisi, penulis1, penulis2, penulis3, terbit, kode)!=EOF)
   		{
   			printf ("\n");
        	printf("Judul Buku    : %s %s %s %s %s\n",buku1, buku2, buku3, buku4, buku5);
       		printf("Edisi         : %s\n", edisi);
       		printf("Penulis       : %s %s %s\n", penulis1, penulis2, penulis3);
       		printf("Terbit        : %s\n", terbit);
       		printf("Kode Buku     : %s\n", kode);
		}
	fclose(out);
	system ("pause");
	system ("cls");
	menu();
}

void help()
{
	printf ("\n		");
	system("pause");
	system("cls");
	help_header();
	printf("\n1. Aplikasi ini bertujuan untuk merekam peminjaman buku dan data buku\n   yang tersedia.\n");
	printf("2. Harap memasukkan jumlah data input sesuai yang diminta.\n");
	printf("3. Masukkan biodata peminjam pada menu peminjaman dengan 1 nama depan dan 1 nama belakang (nama peminjam buku).\n");
	printf("4. Contoh input nama pada menu peminjaman :  \n   Nama depan : Ahmad  \n   Nama Belakang : Taufiq  \n");
	printf("5. Input data berlebih akan secara otomatis menjadi data input\n   untuk input selanjutnya.\n");
	printf("6. Hanya dapat meminjam buku yang ada di Daftar Buku Tersedia.\n");
	printf("7. Pada konfirmasi (pertanyaan [Y/N]), 'N' atau'n' berarti kembali ke MENU.\n");
	printf("8. Pada konfirmasi (pertanyaan [Y/N]), selain 'N' atau 'n' berarti melakukan input ulang.\n");
	printf("\nAkan kembali ke MENU. ");
	system("pause");
	system("cls");
	menu();
}



