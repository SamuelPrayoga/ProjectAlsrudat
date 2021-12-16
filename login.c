#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>


typedef struct kota {
	char kode[100];
	char namaKota[100];
} kota;

typedef struct rute {
	char keberangkatan[100];
	char tujuan[100];
	char kode[100];
	char kode1[100];
	char kode2[100];
	char kode4[100];
	int bisnis;
	int premium;
}rute;

typedef struct dataUser{
    int rno; //Member of structure
    char name[20]; //Pointer within structure
    struct subject{ //Structure within Structure
        int scode;
        char name[20]; //Array within structure
        int mark;
    }sub[3]; //Array of Structure
    int total;
    float per;
    
    char ktp[16];
    char nama[100];
    char hp[16];
    char email[100];
    char password[100];
    char repassword[100];
} dataUser;

int pilih1, pilih2, pilih3,pilih4,pilih5,pilih6;
int userbenar,passbenar;
FILE *pf, *pf1;
int i=1;
char hp[12];
char email[30];
char pass[20];
char repass[20];
char namaLengkap[20];
char kar,again = 'y';	
char user[20],passw[20];
char emailAdmin[20], passAdmin[30];


 

	
	
int menu_utama(){
		printf("\n**************************************\n\t\tKereta Api\n**************************************\n");
        printf("Pilih salah satu role anda");
        printf("\n1. User");
        printf("\n2. Admin");
        printf("\n3. Keluar Program\n");
        printf("\n------------------------------------------\n");
        printf("Pilihan Anda -> ");
        scanf("%d",&pilih1);
        printf("\n===========================================\n");
        if(pilih1>3){
     		system("cls");
            printf("INPUT TIDAK SAH, COBA LAGI!\n");
		}switch(pilih1){
			case 1:
				{
				pengguna();
				break;	
			}
			case 2:
				{
					login_admin();
					break;
				}
			case 3:
				{
					system("exit");
				}
		}
	}
	

	void masukanuser(){
	 	pf=fopen("email.txt","r");
	 	fscanf(pf,"%s",email);
	 	fclose(pf);
	}
	void masukanpass(){
	 	pf=fopen("password.txt","r");
	 	fscanf(pf,"%s",pass);
	 	fclose(pf);
	}
		
	
int menu_user(){
	do{
		system("cls");
		printf("========Menu Pengguna========\n");
		printf("SELAMAT DATANG DI PROGRAM KERETA API %s \n", user);
		printf("Menu Tersedia:\n");
		printf("1. Booking Tiket\n");
		printf("2. Kelola Profile\n");
		printf("3. History Pembelian\n");
		printf("4. Logout\n\n");
		printf("Pilihan Anda -> ");
		scanf("%d",&pilih3);
		if(pilih3>4){
			system("cls");
            printf("INPUT SALAH, COBA LAGI!\n");
		}switch(pilih3){
			case 1:
				system("cls");
				printf("Halaman Pemesanan Tiket\n");
				printf("\n===========================");
				printf("Menu Utama [y/t] ? ");
        		again=getch();
        		system("cls");
				break;
				
			case 2:
				system("cls");
				printf("Kelola Profile\n");
				printf("\n===========================");
				printf("Menu Utama [y/t] ? ");
        		again=getch();
        		system("cls");
				break;
			
			case 3:
				system("cls");
				printf("History Pembelian\n");
				printf("\n===========================");
				printf("Menu Utama [y/t] ? ");
        		again=getch();
        		system("cls");
				break;
			
			case 4:
				system("cls");
				menu_utama();
				system("cls");
		}
	}while(again == 'y');
}

int login_user(){
			system("cls");  
			 int i, j, found=0;
    dataUser s1;
    dataUser *s;
    char email[100];
    char password[100];
			printf("======================\n");
			printf("LOGIN\n");
			printf("======================\n");
			fflush(stdin);
			printf("Username : ");
    		scanf("%[^\n]s",email);
    		fflush(stdin);
    		printf("Password : ");
    		scanf("%[^\n]s",password);

    pf = fopen("dataUser.txt","r");
    while(fread(&s1,sizeof(dataUser),1,pf)){
        if(strcmp(s1.email,email)==0){
            if (strcmp(s1.password,password)==0) {	
       			menu_user();
				found = 1;
				fclose(pf);
			}else if(!found){
				login_user();
			}
        }
	}
}
	
	int pengguna(){
		do{
		system("cls");
        printf("\n===========================================\n\t\tHalaman User\n-------------------------------------------\n");
        printf("Pilih salah satu pengguna!");
        printf("\n1. Registrasi\n");
        printf("\n2. Login\n");
        printf("\n3. Keluar");
        printf("\n-------------------------------------------\n");
        printf("Pilihan Anda ->");
        scanf("%d",&pilih2);
        printf("\n===========================================\n");
        if(pilih2>3){
     		system("cls");
            printf("INPUT SALAH, COBA LAGI!\n");
		}switch(pilih2){
			case 1:
				
				system("cls");
				printf("======================\n");
				printf("REGISTRASI\n");
				printf("======================\n");
				
		           	 dataUser *s;
		        	int n,i,j;

		        s = (dataUser*)malloc(100*sizeof(dataUser));
		        pf = fopen("dataUser.txt","w+");
		
		        for(i=0;i<1;i++){
		        	fflush(stdin);
		            printf("Nomor KTP : ");
		            scanf("%[^\n]s",s[i].ktp);
		            fflush(stdin);
		            printf("Nama Lengkap : ");
		            scanf("%[^\n]s",s[i].nama);
		            fflush(stdin);
		            printf("Nomor Handphone : ");
		            scanf("%[^\n]s",s[i].hp);
		            fflush(stdin);
		            printf("Username : ");
		            scanf("%[^\n]s",s[i].email);
		            fflush(stdin);
		            printf("Password : ");
		            scanf("%[^\n]s",s[i].password);
		            fflush(stdin);
		            printf("Masukkan Ulang Password : ");
		            scanf("%[^\n]s",s[i].repassword);
		
		            fwrite(s+i,sizeof(dataUser),1,pf);
				        }
				    fclose(pf);
				
				printf("Kembali ke menu [y/t] ? ");
        		again=getch();
				break;	
			
			case 2:
					login_user();
					break;
				
			case 3:
				
					system("cls");
					menu_utama();
					break;
		
		}
	}while (again == 'y');
}
	
int menu_admin(){
	do{
		system("cls");
		printf("========Menu Admin========\n");
		printf("Welcome Admin \n");
		printf("1. Kelola Akun\n");
		printf("2. Kelola Kota\n");
		printf("3. Kelola Rute\n");
		printf("4. Lihat Pemasukan\n");
		printf("5. Lihat Jadwal Kereta Api\n");
		printf("6. Logout\n");
		printf("Pilihan Anda-> ");
		scanf("%d",&pilih4);
		if(pilih4>6){
			system("cls");
            printf("INPUT SALAH, COBA LAGI!\n");
		}switch(pilih4){
			case 1:
				system("cls");
				printf("Halaman Kelola Akun\n");
				printf("\n===========================\n\n");
				int i, j, found=0;
			    dataUser s1;
			    char ktp[100];
			    fflush(stdin);
			    printf("Masukkan Nomor KTP : ");
			    scanf("%[^\n]s",ktp);
			
			    pf = fopen("dataUser.txt","r");
			    pf1 = fopen("temp.txt","w");
			    while(fread(&s1,sizeof(dataUser),1,pf)){
			        if(strcmp(s1.ktp,ktp)==0){
			            found = 1;
			            printf("--Data Pengguna--");
			            printf("\nNama Lengkap : %s",s1.nama);
			   			printf("\nNomor Handphone : %s",s1.hp);
			   			printf("\nUsername : %s",s1.email);
			   			printf("\nPassword : %s",s1.password);  
			   			
			   			printf("\n\n--Ubah Data Pengguna--");
			            fflush(stdin);
			        	printf("\nNomor KTP : ");
				        fflush(stdin);
				        scanf("%[^\n]s",s1.ktp);
				        fflush(stdin);
				        printf("Nama Lengkap : ");
				        scanf("%[^\n]s",s1.nama);
				        fflush(stdin);
				        printf("Nomor Handphone : ");
				        scanf("%[^\n]s",s1.hp);
				        fflush(stdin);
				        printf("Username : ");
				        scanf("%[^\n]s",s1.email);
				        fflush(stdin);
				        printf("Password : ");
				        scanf("%[^\n]s",s1.password);
				        fflush(stdin);
				        printf("Re-Password : ");
				        scanf("%[^\n]s",s1.repassword);
			        }
			        fwrite(&s1,sizeof(dataUser),1,pf1);
			    }
			    fclose(pf);
			    fclose(pf1);
			
			
			    if(found){
			            pf = fopen("dataUser.txt","w");
			            pf1 = fopen("temp.txt","r");
			
			            while(fread(&s1,sizeof(dataUser),1,pf1)){
			                fwrite(&s1,sizeof(dataUser),1,pf);
			                printf("\n\nData Berhasil Diupdate, Berikut Data Terbaru: ");
			                printf("\nNama Lengkap : %s",s1.nama);
				   			printf("\nNomor Handphone : %s",s1.hp);
				   			printf("\nEmail : %s",s1.email);
				   			printf("\nPassword : %s",s1.password); 
							   		
			            }
			            fclose(pf);
			            fclose(pf1);
			    }
			    			printf("\nMenu Utama [y/t] ? ");
			        		again=getch();
							break;
				
			case 2:
				system("cls");
				kelola_kota();
				break;
			
			case 3:
				system("cls");
				kelola_rute();
				break;
			
			case 4:
				system("cls");
				printf("Lihat Pemasukan\n");
				printf("\n===========================");
				
        		again=getch();
				break;
			
			case 5:
				system("cls");
				printf("Lihat Jadwal Kereta Api\n");
				printf("\n===========================");
				printf("Menu Utama [y/t] ? ");
        		again=getch();
				break;
			
			case 6:
				system("cls");
				menu_utama();
				break;	
		}
	}while(again == 'y');
}	

int login_admin(){
	system("cls");
        printf("\n===========================================\n\t\tHalaman Admin\n-------------------------------------------\n");
        printf("Username : ");
        scanf("%s", &emailAdmin);
        printf("Password : ");
        scanf("%s", &passAdmin);
        if((strcmp(emailAdmin,"admin")==0) && (strcmp(passAdmin,"admin") == 0)){
        	system("cls");
        	menu_admin();	
		}else{
			system("cls");
			printf("Username/password Salah!");
		}
    	    
}


int kelola_kota(){
	do{
	system("cls");
	printf("========KELOLA KOTA========\n");
	printf("1. Tambah Data Kota\n");
	printf("2. Lihat Data Kota\n");
	printf("3. Edit Data Kota\n");
	printf("4. Delete Data Kota\n");
	printf("5. Menu Utama\n");
	printf("\nPilihan : ");
	scanf("%d",&pilih5);
	if(pilih5>5){
		system("cls");
            printf("INPUT SALAH, COBA LAGI!!\n");
	}switch(pilih5){
		case 1:
			
			system("cls");
			printf("======TAMBAH DATA KOTA======\n");
			kota *k;
			FILE *city, *city1;
			int n,i,j;
			
			k = (kota*)malloc(100*sizeof(kota));
			city = fopen("kota.txt","a+");
			
			printf("#TAMBAH DATA KOTA#\n\n");
			for(i=0;i<1;i++){
				printf("Tambah Kota : ");
				fflush(stdin);
			    scanf("%s %s",k[i].kode,k[i].namaKota);
			    fwrite(k+i,sizeof(kota),1,city);
			}
	    
	    fclose(city);	
		printf("Menu Utama [y/t] ? ");
        again=getch();		
			break;
			
		case 2:
			system("cls");
			kota k1;
			int counter = 1;
		    city = fopen("kota.txt","r");
			printf("#LIHAT DATA KOTA#");
			printf("\nData Lengkap Kota");
			printf("\n-------------------------------------------------------------------\n");
			printf("No\t\tKode Kota\t\tNama Kota\n");
			while(fread(&k1,sizeof(kota),1,city)) { 
				printf("%d\t\t%s\t\t\t%s\n",counter,k1.kode,k1.namaKota);
				counter++;
		    }
			printf("\n\n-------------------------------------------------------------------");
    		fclose(city);
            printf("\nMenu Utama [y/t] ? ");
			again=getch();
			break;
			
		case 3:
			system("cls");
			char id_kota[5];
			int found = 0;
			int counter2 = 1;
			city = fopen("kota.txt","r");
			printf("#LIHAT DATA KOTA#");
			printf("\nData Lengkap Kota");
			printf("\n-------------------------------------------------------------------\n");
			printf("No\t\tKode Kota\t\tNama Kota\n");
			while(fread(&k1,sizeof(kota),1,city)) { 
				printf("%d\t\t%s\t\t\t%s\n",counter2,k1.kode,k1.namaKota);
				counter2++;
		    }
			printf("\n\n-------------------------------------------------------------------");
    		fclose(city);
    		
		    char kodeKota[10];
		    fflush(stdin);
		    printf("\nEdit Kota : EDIT_");
		    scanf("%[^\n]s",kodeKota);
		    
		    city = fopen("kota.txt","r");
		    city1= fopen("temp2.txt","w");
		    while(fread(&k1,sizeof(kota),1,city)){
		        if(strcmp(k1.kode,kodeKota)==0){
		        	found ==1;
		        	fflush(stdin);
		            printf("\nKode Kota : ");
		            fflush(stdin);
				    scanf("%[^\n]s",k1.kode);
				    fflush(stdin);
				    printf("Nama Kota : ");
				    scanf("%[^\n]s",k1.namaKota); 	
		        } 
		        fwrite(&k1,sizeof(kota),1,city1);
		    }
		    fclose(city);
		    fclose(city1);
		    
			if(found==0){
            	city = fopen("kota.txt","w");
	            city1 = fopen("temp2.txt","r");
	
	        while(fread(&k1,sizeof(kota),1,city1)){
	           fwrite(&k1,sizeof(kota),1,city);	
            }
            fclose(city);
            fclose(city1);
    }

			break;
		
		case 4:	
			system("cls");
			int counter3 = 1;
		    city = fopen("kota.txt","r");
			printf("#LIHAT DATA KOTA#");
			printf("\nData Lengkap Kota");
			printf("\n-------------------------------------------------------------------\n");
			printf("No\t\tKode Kota\t\tNama Kota\n");
			while(fread(&k1,sizeof(kota),1,city)) { 
				printf("%d\t\t%s\t\t\t%s\n",counter3,k1.kode,k1.namaKota);
				counter3++;
		    }
			printf("\n\n-------------------------------------------------------------------");
    		fclose(city);

    		char kode[10];
		    printf("\nDelete Kota : DELETE_");
		    fflush(stdin);
		    scanf("%[^\n]s",kode);
			
			city = fopen("kota.txt","r");
		    city1 = fopen("temp2.txt","w");
		    
		    while(fread(&k1,sizeof(kota),1,city)){
		        if(strcmp(k1.kode,kode)==0){
		        	found = 1;			
		        }
		        else
		        
		        fwrite(&k1,sizeof(kota),1,city1);   
		    }
		    fclose(city);
		    fclose(city1);
		     if(found){
		        city = fopen("kota.txt","w");
		        city1 = fopen("temp2.txt","r");
		
		        while(fread(&k1,sizeof(kota),1,city1)){
		            fwrite(&k1,sizeof(kota),1,city);
		        }
		        fclose(city);
		        fclose(city1);
		        printf("\nData telah berhasil dihapus\n");
    		}
    		
            printf("Menu Utama [y/t] ? ");
			again=getch();
			break;
		
		case 5:
			system("cls");
			menu_admin();
			system("cls");
			break;
	}
	}while(again == 'y');	
}

int lihat_rute(){
	rute *r;
	rute r1;
	kota k1;
    FILE *prute,*prute1;
    int n,i,j, found =0;
	int counter4=1;
    prute = fopen("rute.txt","r");
	system("cls");
	printf("\n\n#LIHAT DATA RUTE#");
	printf("\nData Lengkap Rute Kereta Api");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKeberangkatan\tTujuan\t\tKode_Rute\t\tBisnis\t\tPremium\n");
	while(fread(&r1,sizeof(rute),1,prute)) { 
		printf("%d\t\t%s\t\t%s\t\t%s-%s\t\t\t%d\t\t\%d\n",counter4,r1.keberangkatan,r1.tujuan,r1.kode1,r1.kode2,r1.bisnis,r1.premium);
		counter4++;
    }
	printf("\n\n-------------------------------------------------------------------");
    fclose(prute);
}
int kelola_rute(){
	do{
	system("cls");
	printf("========KELOLA KOTA========\n");
	printf("1. Tambah Data Rute\n");
	printf("2. Lihat Data Rute\n");
	printf("3. Edit Data Rute\n");
	printf("4. Delete Data Rute\n");
	printf("5. Menu Utama\n");
	printf("\nPilihan : ");
	scanf("%d",&pilih6);
	if(pilih6>5){
		system("cls");
            printf("INPUT SALAH, COBA LAGI!!\n");
	}switch(pilih6){
		case 1:
		system("cls");
		rute *r;
		rute r1;
		kota k1;
	    FILE *prute,*prute1;
	    int n,i,j, found =0;
	
	    r = (rute*)malloc(100*sizeof(rute));
	    prute = fopen("rute.txt","a+");
	    prute1 = fopen("kota.txt","r");
	    
		printf("#TAMBAH DATA RUTE#\n\n");
		char kode1[100], kode2[100], kode3[100];
		
	    	printf("Tambah Data Rute : ");
	    	fflush(stdin);
	        scanf("%s %s %d %d",r1.keberangkatan,r1.tujuan,&r1.bisnis,&r1.premium);
	        while(fread(&k1,sizeof(kota),1,prute1)) {
	            if(strcmp(r1.keberangkatan,k1.namaKota)==0) {
	            	strcpy(r1.kode1,k1.kode);
				} 
				
				if (strcmp(r1.tujuan,k1.namaKota)==0) {
					strcpy(r1.kode2,k1.kode);
				}
				strcpy(kode3,strcat(r1.kode1,""));
				strcpy(r1.kode,(strcat(kode3,r1.kode2)));
	        }
	        
	        fwrite(&r1,sizeof(rute),1,prute);
	    
	    
	    printf("\n-----------------------------------------");
	    printf("\nData Berhasil Ditambahkan\n");
	    printf("------------------------------------------");
	    
	    fclose(prute);
	    fclose(prute1);
	    printf("\nMenu Utama [y/t] ? ");
		again=getch();
		break;
		
		case 2:
			system("cls");
		    lihat_rute();
		    printf("\nMenu Utama [y/t] ? ");
			again=getch();
		break;
		
		case 3:
		system("cls");
		int counter5 =1;
			prute = fopen("rute.txt","r");
			system("cls");
			lihat_rute();
			char kodeKota[100];
			printf("\n\n#EDIT DATA RUTE#");
			fflush(stdin);
		    printf("\n\nEdit Rute : EDIT_");
		    scanf("%[^\n]s",kodeKota);
		    
		    pf= fopen("kota.txt","r");
		    prute = fopen("rute.txt","r");
		    prute1 = fopen("temp3.txt","w");
		    	while(fread(&r1,sizeof(rute),1,prute)){
		        	if(strcmp(r1.kode,kodeKota)==0){
		       			found = 1;
				    	fflush(stdin);
			            printf("\nKeberangkatan : ");
					    scanf("%[^\n]s",r1.keberangkatan);
					    fflush(stdin);
					    printf("Tujuan : ");
					    scanf("%[^\n]s",r1.tujuan);
					    fflush(stdin);
					    printf("Bisnis : ");
					    scanf("%d",&r1.bisnis);
					    fflush(stdin);
					    printf("Premium : ");
					    scanf("%d",&r1.premium);
						    
						while(fread(&k1,sizeof(kota),1,pf)) {
				            if(strcmp(r1.keberangkatan,k1.namaKota)==0) {
				            	strcpy(r1.kode1,k1.kode);
							} 
							if (strcmp(r1.tujuan,k1.namaKota)==0) {
								strcpy(r1.kode2,k1.kode);
							}
							strcpy(kode3,strcat(r1.kode1,"-"));
							strcpy(r1.kode,(strcat(kode3,r1.kode2)));
				        }
					}
					fwrite(&r1,sizeof(rute),1,prute1); 
		    }
		    fclose(pf);
		    fclose(prute);
		    fclose(prute1);
		    
		    if (found==1) {
		    	prute = fopen("rute.txt","w");
		    	prute1 = fopen("temp3.txt","r");
		    	
				while(fread(&r1,sizeof(rute),1,prute1)) {
		            fwrite(&r1,sizeof(rute),1,prute);
		            
		        }
		        fclose(prute);
			    fclose(prute1);
				printf("Data berhasil diubah");
			}	
			printf("\nMenu Utama [y/t] ? ");
			again=getch();
		break;
		
		case 4:
		printf("s");
		break;
		
		case 5:
		system("cls");
		menu_admin();
		system("cls");
	}
}while(again == 'y');
}

