#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/uio.h>
#include <stdio.h>
#include <conio.h>
#include <i86.h>
#include <mqueue.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fd.h>
#include <sys/prfx.h>
#include <termios.h>


#include <sys/io_msg.h>
#include <sys/dev_msg.h>
#include <sys/psinfo.h>
#include <sys/name.h>
#include 				<conio.h>
#include				<process.h>
#include				<sys/kernel.h>
#include				<sys/seginfo.h>
#include				<signal.h>
#include				<sys/vc.h>
#include				<sys/sched.h>
#include				<sys/mman.h>
#include				<sys/timers.h>
#include				<fcntl.h>
#include				<time.h>
#include				<math.h>






#include "moe.h"

typedef struct {
              time_t vrem;
              SMES dat;
              NATEK natekanie;
			  info plavka;
              }Sender;


typedef union {
              short int  Sav[127];
              char  Save[254];
              }Soxr;

typedef struct {
              Sender P1;
              Sender P2;
              }MEMORY;

MEMORY orig,*polue;

int err;
Soxr sd, sd1;

int erar,vak,plav,erplav,pl_byl;

discret D1,D2;
time_t vremya;
char poisk[30],nm[30],num[5],newt[10],ipat[100],errplav[200];
char buf[10],poslanie[30],rezv[10],name1[50],name[30],pol[30],name2[30],nuzla[5],poisk2[30];         
char year[10],month[10],newyear[10],newmonth[10],day[10],newday[10],all[100],dir2[20],newh[20],newm[20],news[20];
char all1[100],all2[100],all3[100],buff[100],buff1[40],sm[20],newnatek[20];
char sav_1[100],sav_2[100],sav_11[100],sav_12[100],sav_21[100],sav_22[100];
char all4[100],all5[100],ldir[40],lall[100],lall1[100],lall2[100],lall3[100];
char tempfile1[40],tempfile2[40],tempfile3[40],oldPlav[40],tname[L_tmpnam];
char Save_array[2000];
short int Zap,len1,tmp;
long int newtime,oldtime,smin,sofs;
struct itimerspec timer;
struct sigevent event;
int arhiv,iii,arhiv1,arhiv2,larhiv,error0,error1,error2,zapNplav,error3,error4;
int arhiv3,arhiv4;
int foripatov,IpatovDubel,sost,f_nomer_pl;
int f1,i_nomer_pl;;
time_t id;
char ii, jj,s_nomer_pl;
struct tm timers;




struct mq_attr attr,old_attr;
unsigned int prio;


main()
{
int ji;
mqd_t mqid;
Sender Dann;

putch(12);
error0=error1=error2=0;
strcpy(newnatek,"");

err=shm_open("Pech2",O_RDWR|O_CREAT,0);
ltrunc(err,sizeof(orig),SEEK_SET);
polue=mmap(0,sizeof(orig),PROT_READ|PROT_WRITE,MAP_SHARED,err,0);




Zap=0;
vak=0;
sofs =0;
sost=open("/sost.plv",O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (sost !=-1){
read (sost,&erar,sizeof(erar));
read (sost,&vak,sizeof(vak));
read (sost,&plav,sizeof(plav));
read (sost,&erplav,sizeof(erplav));
read (sost,&pl_byl,sizeof(pl_byl));
close (sost);
}




for (;;){
mqid=mq_open("pech2.mem",O_RDONLY);
if (mqid != -1){

strcpy(oldPlav,"");
             for (;;){
                    delay(50);
					mqid=mq_open("pech2.mem",O_RDONLY);
                     mq_receive(mqid,&Dann,sizeof(Dann),&prio); 
                     mq_close(mqid);  
//                    printf("%d Error %d  %d\n",mqid,errno,sizeof(Dann));
//                    printf("%d\n",i);

					  vremya = Dann.vrem;
                      for (ji=0;ji<5;ji++) polue->P2.dat.odin[ji]=Dann.dat.odin[ji];
                      for (ji=0;ji<60;ji++) polue->P2.dat.dva[ji]=Dann.dat.dva[ji];
                      for (ji=0;ji<10;ji++) polue->P2.dat.tri[ji]=Dann.dat.tri[ji];
                      for (ji=0;ji<60;ji++) polue->P2.dat.z[ji]=Dann.dat.z[ji];
                      for (ji=0;ji<6;ji++) polue->P2.dat.RPI[ji]=Dann.dat.RPI[ji];
                     
                      polue->P2.dat.vakuum=Dann.dat.vakuum;
                      polue->P2.natekanie=Dann.natekanie;
                      polue->P2.plavka=Dann.plavka;
//                    printf("Kuku %s %d\n",Dann.natekanie.sttim,mqid);


if (Zap != 0) sd1=sd;				
				strftime(newyear,10,"/%Y",localtime(&vremya));
				strftime(newmonth,10,"%m",localtime(&vremya));
				strftime(newday,10,"%d",localtime(&vremya));
   				strftime(newm,10,"%M",localtime(&vremya));
				strftime(newh,10,"%H",localtime(&vremya));
				strftime(news,10,"%S",localtime(&vremya));
				oldtime = newtime;
                
				newtime = atoi(news)+atoi(newm)*60+atoi(newh)*3600;
				sprintf(newt,"%d",newtime);

//printf("%s:%s:%s   %d\n",newyear,newmonth,newday,newtime);
			if (newtime == 0) Zap=0;
            strcpy(ldir,"//92/hd1");
			strcpy(dir2,"");
			strcat(dir2,newyear);
			strcat(dir2,newmonth);
			strcpy(all,"//11/VDP/92");
			strcpy(all2,"//12/VDP/92");
			strcpy(sav_1,"//101/GRE/92");
			strcpy(sav_2,"//102/GRE/92");

//strcpy(all,"");

strcpy(tempfile1,"//11/stp/spool");
strcpy(tempfile2,"//12/stp/spool");
strcpy(tempfile3,"//92/hd1");

			strcat(all,newyear);
			strcat(all,newmonth);
			strcat(all,newday);
			strcpy(all1,all);
            strcpy(all4,all);
			strcat(all,".921");
			strcat(all1,".923");
            strcat(all4,".922");

            //Local saving

			strcpy(lall,"//92/hd1");

            strcat(lall,newyear);
			strcat(lall,newmonth);
			strcat(lall,newday);
			strcpy(lall1,lall);
            strcpy(lall2,lall);
			strcat(lall,".921");
			strcat(lall1,".923");
            strcat(lall2,".922");

		    // End Local saving

			strcat(all2,newyear);
			strcat(all2,newmonth);
			strcat(all2,newday);
			strcpy(all3,all2);
			strcpy(all5,all2);
			strcat(all2,".921");
			strcat(all5,".922");
			strcat(all3,".923");

        // Save to Korpus_NEW

			strcat(sav_1,newyear);
			strcat(sav_1,newmonth);
			strcat(sav_1,newday);
			strcpy(sav_11,sav_1);
            strcpy(sav_12,sav_1);
			strcat(sav_1,".921");
			strcat(sav_11,".923");
            strcat(sav_12,".922");

			strcat(sav_2,newyear);
			strcat(sav_2,newmonth);
			strcat(sav_2,newday);
			strcpy(sav_21,sav_2);
            strcpy(sav_22,sav_2);
			strcat(sav_2,".921");
			strcat(sav_21,".923");
            strcat(sav_22,".922");

       // End Save to Korpus_NEW




//printf("%s   \n",all);
//printf("%s   \n",all2);
//printf("%s   \n",lall);
//printf("%s   \n",sav_1);
//printf("%s   \n",sav_2);
if ( strcmp(newyear,year)!=0 ){
                strcpy(year,newyear);
                              }

if ( strcmp(newmonth,month)!=0 ){
                strcpy(month,newmonth);
	                           }
 
/*Nomer plavki*/
//printf("%s \n",Dann.plavka.Nplavki);

strcpy(buff,"");

      tmp=strlen(Dann.plavka.Nplavki);
      if ((tmp<10) && (tmp>8)){
errplav[0]=Dann.plavka.Nplavki[0];
errplav[1]=Dann.plavka.Nplavki[1];
errplav[2]=Dann.plavka.Nplavki[2];
errplav[3]=Dann.plavka.Nplavki[3];
errplav[4]=Dann.plavka.Nplavki[4];
errplav[5]=0x30;
errplav[6]=Dann.plavka.Nplavki[5];
errplav[7]=Dann.plavka.Nplavki[6];
errplav[8]=Dann.plavka.Nplavki[7];
errplav[9]=Dann.plavka.Nplavki[8];
errplav[11]=0;
strcpy(Dann.plavka.Nplavki,errplav);
                 }

if (strcmp(oldPlav,Dann.plavka.Nplavki)!=0){



//printf("Pomnu %s  %d\n",oldPlav,strlen(oldPlav));
   if (strcmp(Dann.plavka.Nplavki,"")!=0){
      strcpy(oldPlav,Dann.plavka.Nplavki);

							tmpnam(tname);
							strcat(tname,"90");
							strcat(tempfile1,tname);
                            strcat(tempfile2,tname);
                            strcat(tempfile3,tname);
//printf("Prishlo %s  %d\n",Dann.plavka.Nplavki,strlen(Dann.plavka.Nplavki));								

               IpatovDubel=open(tempfile3,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
				if (IpatovDubel!=-1){
						strcpy(ipat,"PLAV_KORPUS");
						write(IpatovDubel,ipat,strlen(ipat));
                        tmp=strlen(oldPlav);
                        write(IpatovDubel,&tmp,sizeof(tmp));
                        write(IpatovDubel,oldPlav,strlen(oldPlav));
                        tmp=0;
                        write(IpatovDubel,&tmp,1);
                        write(IpatovDubel,&vremya,sizeof(vremya));
			            close(IpatovDubel);
				}



 }
}


/*					 Vakuumirovanie					   */




if (Dann.dat.dva[55].temp<-10 && vak==0 ){
                                     vak=1;
			strcpy(buff,"");
			strcat(buff,"08");
			strcat(buff,"	");
			strcat(buff,newh);
			strcat(buff,":");
			strcat(buff,newm);
			strcat(buff,":");
			strcat(buff,news);
			strcat(buff,"	");
            ltoa(vremya,buff1,10);
            strcat(buff,buff1);
            strcat(buff,"\n");

arhiv1=open(all1,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
            write(arhiv1,buff,strlen(buff));
            close(arhiv1);
              }

arhiv1=open(all3,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
       write(arhiv1,buff,strlen(buff));
       close(arhiv1);
               }
arhiv1=open(lall1,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
			write(arhiv1,buff,strlen(buff));
	        close(arhiv1);
				}

arhiv1=open(sav_11,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
            write(arhiv1,buff,strlen(buff));
            close(arhiv1);
              }

arhiv1=open(sav_21,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
            write(arhiv1,buff,strlen(buff));
            close(arhiv1);
              }



							}	



/*					 proverka natekania					   */




if (strcmp(polue->P2.natekanie.edtim,newnatek)!=0 && strcmp(polue->P2.natekanie.sttim,"")!=0 && strcmp(polue->P2.natekanie.edtim,"")!=0){
                                     strcpy(newnatek,polue->P2.natekanie.edtim);
arhiv1=open(all4,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
			strcpy(buff,"");
			strcat(buff,"22");
			strcat(buff,"	");
			strcat(buff,polue->P2.natekanie.sttim);
			strcat(buff,"	");
			strcat(buff,polue->P2.natekanie.edtim);
			strcat(buff,"\n");
			write(arhiv1,buff,strlen(buff));
			strcpy(buff,"P1=");
			strcat(buff,polue->P2.natekanie.stnat);
            strcat(buff,"	");
			strcat(buff,"P2=");
			strcat(buff,polue->P2.natekanie.ednat);
            strcat(buff,"	");
			strcat(buff,"T1=");
			strcat(buff,polue->P2.natekanie.sttim);
            strcat(buff,"	");
			strcat(buff,"T2=");
			strcat(buff,polue->P2.natekanie.edtim);
            strcat(buff,"	");
			strcat(buff,"Vs=");
			strcat(buff,polue->P2.natekanie.natek);
            strcat(buff,"\n");
			write(arhiv1,buff,strlen(buff));
            strcpy(buff,"\n");
            write(arhiv1,buff,strlen(buff));
            close(arhiv1);
			}
            
arhiv1=open(all5,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
					strcpy(buff,"");
			strcat(buff,"22");
			strcat(buff,"	");
			strcat(buff,polue->P2.natekanie.sttim);
			strcat(buff,"	");
			strcat(buff,polue->P2.natekanie.edtim);
			strcat(buff,"\n");
			write(arhiv1,buff,strlen(buff));
			strcpy(buff,"P1=");
			strcat(buff,polue->P2.natekanie.stnat);
            strcat(buff,"	");
			strcat(buff,"P2=");
			strcat(buff,polue->P2.natekanie.ednat);
            strcat(buff,"	");
			strcat(buff,"T1=");
			strcat(buff,polue->P2.natekanie.sttim);
            strcat(buff,"	");
			strcat(buff,"T2=");
			strcat(buff,polue->P2.natekanie.edtim);
            strcat(buff,"	");
			strcat(buff,"Vs=");
			strcat(buff,polue->P2.natekanie.natek);
            strcat(buff,"\n");
			write(arhiv1,buff,strlen(buff));
            strcpy(buff,"\n");
            write(arhiv1,buff,strlen(buff));	
       close(arhiv1);
			}

							}	

/*						 PLAVKA					 */


if (Dann.dat.odin[0].voltage>2.0 && Dann.dat.odin[1].voltage>4 ){
										if (erplav<10) erplav++;
											}
else {
      if (erplav>0) erplav=erplav-1;
     }
if (Dann.dat.odin[0].voltage>1.0 && vak==1 && plav==0 && erplav>5 ){
                                     plav=1;
            pl_byl=1;
			strcpy(buff,"");
			strcat(buff,"10");
			strcat(buff,"	");
			strcat(buff,newh);
			strcat(buff,":");
			strcat(buff,newm);
			strcat(buff,":");
			strcat(buff,news);
			strcat(buff,"	");
            ltoa(vremya,buff1,10);
            strcat(buff,buff1);
            strcat(buff,"\n");

arhiv1=open(all1,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
            write(arhiv1,buff,strlen(buff));
            close(arhiv1);
			}
arhiv1=open(all3,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
			write(arhiv1,buff,strlen(buff));
       close(arhiv1);
				}
arhiv1=open(lall1,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
			write(arhiv1,buff,strlen(buff));
	        close(arhiv1);
				}

arhiv1=open(sav_11,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
            write(arhiv1,buff,strlen(buff));
            close(arhiv1);
              }

arhiv1=open(sav_21,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
            write(arhiv1,buff,strlen(buff));
            close(arhiv1);
              }

							}	




/*						 Ostivanie					 */


if (Dann.dat.odin[0].voltage<1.0 && plav==1 ){
					if (strcmp(sm,newm)!=0){ 
					                          smin++;
											strcpy(sm,newm);
					                       }
                      if (smin>30){ 
                                     plav=0;
			strcpy(buff,"");
			strcat(buff,"12");
			strcat(buff,"	");
			strcat(buff,newh);
			strcat(buff,":");
			strcat(buff,newm);
			strcat(buff,":");
			strcat(buff,news);
			strcat(buff,"	");
            ltoa(vremya,buff1,10);
            strcat(buff,buff1);
            strcat(buff,"\n");

arhiv1=open(all1,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
            write(arhiv1,buff,strlen(buff));
            close(arhiv1);
				}
arhiv1=open(all3,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
			write(arhiv1,buff,strlen(buff));
	        close(arhiv1);
			   }
arhiv1=open(lall1,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
			write(arhiv1,buff,strlen(buff));
	        close(arhiv1);
				}
arhiv1=open(sav_11,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
            write(arhiv1,buff,strlen(buff));
            close(arhiv1);
              }

arhiv1=open(sav_21,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
            write(arhiv1,buff,strlen(buff));
            close(arhiv1);
              }

							}


														}
else smin=0;





/*                   Vskritie pechi                    */



if (Dann.dat.dva[55].temp>-10 && vak==1 && pl_byl==1 ){
                                     vak=0;
                                     pl_byl=0;
arhiv1=open(all1,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
			strcpy(buff,"");
			strcat(buff,"00");
			strcat(buff,"	");
			strcat(buff,newh);
			strcat(buff,":");
			strcat(buff,newm);
			strcat(buff,":");
			strcat(buff,news);
			strcat(buff,"	");
	        ltoa(vremya,buff1,10);
            strcat(buff,buff1);
            strcat(buff,"\n");
            write(arhiv1,buff,strlen(buff));
			strcpy(buff,"");
			strcat(buff,"13");
			strcat(buff,"	");
			strcat(buff,newh);
			strcat(buff,":");
			strcat(buff,newm);
			strcat(buff,":");
			strcat(buff,news);
			strcat(buff,"	");
	        ltoa(vremya,buff1,10);
            strcat(buff,buff1);
            strcat(buff,"\n");
            write(arhiv1,buff,strlen(buff));
            close(arhiv1);
			}
arhiv1=open(all3,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
		    strcpy(buff,"");
			strcat(buff,"00");
			strcat(buff,"	");
			strcat(buff,newh);
			strcat(buff,":");
			strcat(buff,newm);
			strcat(buff,":");
			strcat(buff,news);
			strcat(buff,"	");
	        ltoa(vremya,buff1,10);
            strcat(buff,buff1);
            strcat(buff,"\n");
            write(arhiv1,buff,strlen(buff));
			strcpy(buff,"");
			strcat(buff,"13");
			strcat(buff,"	");
			strcat(buff,newh);
			strcat(buff,":");
			strcat(buff,newm);
			strcat(buff,":");
			strcat(buff,news);
			strcat(buff,"	");
	        ltoa(vremya,buff1,10);
            strcat(buff,buff1);
            strcat(buff,"\n");
            write(arhiv1,buff,strlen(buff));
            close(arhiv1);
			    }
arhiv1=open(lall1,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
		    strcpy(buff,"");
			strcat(buff,"00");
			strcat(buff,"	");
			strcat(buff,newh);
			strcat(buff,":");
			strcat(buff,newm);
			strcat(buff,":");
			strcat(buff,news);
			strcat(buff,"	");
	        ltoa(vremya,buff1,10);
            strcat(buff,buff1);
            strcat(buff,"\n");
            write(arhiv1,buff,strlen(buff));
			strcpy(buff,"");
			strcat(buff,"13");
			strcat(buff,"	");
			strcat(buff,newh);
			strcat(buff,":");
			strcat(buff,newm);
			strcat(buff,":");
			strcat(buff,news);
			strcat(buff,"	");
	        ltoa(vremya,buff1,10);
            strcat(buff,buff1);
            strcat(buff,"\n");
            write(arhiv1,buff,strlen(buff));
            close(arhiv1);
      			 }

arhiv1=open(sav_11,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
		    strcpy(buff,"");
			strcat(buff,"00");
			strcat(buff,"	");
			strcat(buff,newh);
			strcat(buff,":");
			strcat(buff,newm);
			strcat(buff,":");
			strcat(buff,news);
			strcat(buff,"	");
	        ltoa(vremya,buff1,10);
            strcat(buff,buff1);
            strcat(buff,"\n");
            write(arhiv1,buff,strlen(buff));
			strcpy(buff,"");
			strcat(buff,"13");
			strcat(buff,"	");
			strcat(buff,newh);
			strcat(buff,":");
			strcat(buff,newm);
			strcat(buff,":");
			strcat(buff,news);
			strcat(buff,"	");
	        ltoa(vremya,buff1,10);
            strcat(buff,buff1);
            strcat(buff,"\n");
            write(arhiv1,buff,strlen(buff));
            close(arhiv1);
      			 }
arhiv1=open(sav_21,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (arhiv1!=-1){
		    strcpy(buff,"");
			strcat(buff,"00");
			strcat(buff,"	");
			strcat(buff,newh);
			strcat(buff,":");
			strcat(buff,newm);
			strcat(buff,":");
			strcat(buff,news);
			strcat(buff,"	");
	        ltoa(vremya,buff1,10);
            strcat(buff,buff1);
            strcat(buff,"\n");
            write(arhiv1,buff,strlen(buff));
			strcpy(buff,"");
			strcat(buff,"13");
			strcat(buff,"	");
			strcat(buff,newh);
			strcat(buff,":");
			strcat(buff,newm);
			strcat(buff,":");
			strcat(buff,news);
			strcat(buff,"	");
	        ltoa(vremya,buff1,10);
            strcat(buff,buff1);
            strcat(buff,"\n");
            write(arhiv1,buff,strlen(buff));
            close(arhiv1);
      			 }








							}	








erar=errno;

//preobrazovanie dla zapisi


for (jj=0;jj<60;jj++) sd.Sav[jj]=Dann.dat.dva[jj].temp*10; 
// 60

for (jj=0;jj<3;jj++) sd.Sav[jj+60]=Dann.dat.odin[jj].voltage*10; 
//63

// preobrazovanie vakuuma

if (Dann.dat.odin[3].voltage<=3276.7) {
                            sd.Sav[63]=Dann.dat.odin[3].voltage*10; 
                                }
else {
       sd.Sav[63]=Dann.dat.odin[3].voltage/100.0-32767.0; 
     }

//65
//                          Diskrety
// 130
for (jj=0;jj<10;jj++) sd.Save[jj+130]=Dann.dat.tri[jj].p; 
// 140
for (jj=0;jj<60;jj++) sd.Save[jj+140]=Dann.dat.z[jj].p; 
// 200
for (jj=0;jj<6;jj++) sd.Save[jj+200]=Dann.dat.RPI[jj].p; 
// 206

D1.bit.b0 = Dann.dat.vakuum.pervd;
D1.bit.b1 = Dann.dat.vakuum.vtord;
D1.bit.b2 = Dann.dat.vakuum.avar1;
D1.bit.b3 = Dann.dat.vakuum.avar2;


sd.Save[206]=D1.p; 
D1.bit.b0 = Dann.dat.err.exist_error;   //nalichie avarii
D1.bit.b1 = Dann.dat.err.error_chenge;  //dobavlenie avarii 
//D1.bit.b0 = Dann.dat.err.tpu_error[30]; //termopari ustavki
//D1.bit.b0 = Dann.dat.err.tpg_error[30]; //termopari gradient
//D1.bit.b0 = Dann.dat.err.tcm_error[30]; //tcm ustavki
//D1.bit.b0 = Dann.dat.err.rpi_error[20]; //protok rpi
D1.bit.b2 = Dann.dat.err.box_error;     //dver boksa
D1.bit.b3 = Dann.dat.err.I_error;       //tok otklonenie
D1.bit.b4 = Dann.dat.err.U_error;       //napriagenie ustavka
D1.bit.b5 = Dann.dat.err.Q_error;       //rashod vodi ustavka
D1.bit.b6 = Dann.dat.err.P_error;       //vakuum ustavka
D1.bit.b7 = Dann.dat.err.P_off;         //otkl Vakuummetra
D2.bit.b0 = Dann.dat.err.PM_error;      //podgatie elektroda
D2.bit.b1 = Dann.dat.err.Vodooborot;    //Davlenie i rashod vodi
if (Dann.dat.err.Natek_error==1) {
                                 D2.bit.b2 = 1;    //Natekanie
                                 D2.bit.b3 = 0;
                                 }
if (Dann.dat.err.Natek_error==2) {
                                D2.bit.b2 = 0;
                                D2.bit.b3 = 1;    //Vrema Natekania
                                 }

sd.Save[207]=D1.p;
sd.Save[208]=D2.p;  

if (arhiv==-1) {error0++;
               if (error0>500) error0=0;
               }
//printf ("Start open //11 \n");
if (error0==0) arhiv=open(all,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
//printf ("//11 opened /d arhiv \n",arhiv);

if (arhiv2==-1) {error1++;
               if (error1>500) error1=0;
               }
if (error1==0) arhiv2=open(all2,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	

if (larhiv==-1) {error2++;
               if (error2>500) error2=0;
               }
if (error2==0)larhiv=open(lall,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	

if (arhiv3==-1) {error3++;
               if (error3>500) error3=0;
               }
if (error3==0) arhiv3=open(sav_1,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	

if (arhiv4==-1) {error4++;
               if (error4>500) error4=0;
               }
if (error4==0) arhiv4=open(sav_2,O_APPEND|O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	





if (Zap == 0){
             if (newtime != 0) { 
                               ii=0xfb;
                               sofs++;
                               Save_array[sofs-1]=ii;
                               sofs++;
                               Save_array[sofs-1]=(newtime& 0xff);
                               sofs++;
                               Save_array[sofs-1]=(newtime & 0xff00)>>8;
                               sofs++;
                               Save_array[sofs-1]=(newtime & 0xff0000)>>16;
                               sofs++;
                               Save_array[sofs-1]=(newtime & 0xff000000)>>24;
                             
                               } 
             for (jj=0;jj<208;jj++)
                              {               
                               sofs++;
                               Save_array[sofs-1]=jj;
                               sofs++;
                               Save_array[sofs-1]=sd.Save[jj];
                               }            
             Zap = 1;
             }
else  {

                               ii=0xfb;
                               sofs++;
                               Save_array[sofs-1]=ii;
                               sofs++;
                               Save_array[sofs-1]=(newtime& 0xff);
                               sofs++;
                               Save_array[sofs-1]=(newtime & 0xff00)>>8;
                               sofs++;
                               Save_array[sofs-1]=(newtime & 0xff0000)>>16;
                               sofs++;
                               Save_array[sofs-1]=(newtime & 0xff000000)>>24;

//       printf("Proverka \n");
             for (jj=0;jj<208;jj++){

                               if (sd.Save[jj] != sd1.Save[jj]){
//                                                             printf("Chenged N %d Z %d\n",jj,sd.Save[jj]);
                               sofs++;
                               Save_array[sofs-1]=jj;
                               sofs++;
                               Save_array[sofs-1]=sd.Save[jj];

         
                                                              } 
             	                  } 
       
                   
      } 
 
 ii=0xff;
 sofs++;
 Save_array[sofs-1]=ii;

if (arhiv!=-1){
 write(arhiv,Save_array,sofs);
 close(arhiv);       
              }
if (larhiv!=-1){
 write(larhiv,Save_array,sofs);
 close(larhiv);        
               }
if (arhiv2!=-1){
 write(arhiv2,Save_array,sofs);
// write(arhiv2,&ii,1);
 close(arhiv2);        
				}

if (arhiv3!=-1){
 write(arhiv3,Save_array,sofs);
// write(arhiv3,&ii,1);
 close(arhiv3);        
				}
if (arhiv4!=-1){
 write(arhiv4,Save_array,sofs);
// write(arhiv4,&ii,1);
 close(arhiv4);        
				}

sofs=0;
//printf("Saved %d %d %d   \n",error0,error1,error2);

sost=open("/sost.plv",O_CREAT|O_RDWR|O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );	
if (sost !=-1){
write (sost,&erar,sizeof(erar));
write (sost,&vak,sizeof(vak));
write (sost,&plav,sizeof(plav));
write (sost,&erplav,sizeof(erplav));
write (sost,&pl_byl,sizeof(pl_byl));
close (sost);
}



                     }
             }

}

}