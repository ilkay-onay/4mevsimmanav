/* Öðrenci numarasý : 2112721017 */
/* Öðrenci adý : Ýlkay Onay */
/* Proje adý : 4mevsimnv */
/* Proje konusu : "Manav Otomasyonu" */

#include <iostream>
#include <fstream>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;
 
char istek, tekrar;
int urun,secim,secim2,minn,maks,minmaks,maksmaks;
float kilo, toplamfiyat = 0;
string s1 = "MANTAR",s2 = "PATATES",s3 = "SOÐAN",s4 = "DOMATES",s5 = "PATLICAN",s6 = "HAVUC",s7 = "BIBER",s8 = "SALATALIK",s9 = "LIMON",s10 = "FASULYE",s11 = "KABAK",s12 = "SARIMSAK",s13 = "LAHANA",s14 = "PIRASA",s15 = "BROKOLÝ",s16 = "MUZ",s17 = "SÝLOR",s18 = "TURP",s19 = "ISPANAK",s20 = "KEREVÝZ",s21 = "KARNABAHAR",s22 = "SEMÝZOTU",s23 = "LAHANA";
string m1 = "PORTAKAL",m2 = "ÇÝLEK",m3 = "ERÝK",m4 = "ELMA",m5 = "KARPUZ",m6 = "KAVUN",m7 = "ARMUT",m8 = "MANDALÝNA",m9 = "KÝVÝ",m10 = "ÜZÜM",m11 = "NEKTARÝN",m12 = "NAR",m13 = "AVAKADO",m14 = "ÞEFTALÝ",m15 = "GREYFURT";
struct urunler
{
    
//Sebzeler
 float mantar,patates,sogan,domates,patlican,havuc,biber,salatalik,limon,fasulye,kabak,sarimsak,lahana,pirasa,brokoli,turp,muz,silor,ispanak,kereviz,karnabahar,semizotu,bezelye;
 
//Meyveler
 float cagla,portakal,cilek,erik,elma,karpuz,kavun,armut,mandalina,kivi,ayva,uzum,nektarin,seftali,nar,avakado,greyfurt; 
};

//Fonksiyonlar
 
void fiyatliste(urunler& fiyat);
float hesapla(urunler& fiyat,urunler& stok,urunler& alis,urunler& kazanc);
void alisliste(urunler& alis);
void stokliste(urunler& stok);
void kazancliste(urunler& kazanc);
float guncelle(urunler& fiyat);
float guncelle2(urunler& alis);
float depo(urunler& stok);
float guncelle5();
void fiyatsifirla(urunler& fiyat);
void alissifirla(urunler& alis);
void stoksifirla(urunler& stok);
void kazancsifirla(urunler& kazanc);
void ayarlarsifirla();
void sifirlamamenu(urunler& fiyat, urunler& alis, urunler& stok, urunler& kazanc);

//Ana Program

int main()
{
setlocale(LC_ALL, "Turkish"); 
urunler fiyat, alis, stok, kazanc;

while((tekrar != 'H') && (tekrar != 'h'))
{
cout << "                             *****************************************************************" << endl;
cout << "                             |                 4mevsimnv v1.10'a hoþgeldiniz!                |" << endl; // :)
cout << "                             |                                                               |" << endl;
cout << "                             | Fonksiyonlar                                                  |" << endl;
cout << "                             |                                                               |" << endl;
cout << "                             |                                                               |" << endl; //Günlük müþteriye sebze ve meyve satýþ iþlemleri
cout << "                             | 1. Alýþveriþ iþlemleri                                        |" << endl;
cout << "                             |                                                               |" << endl;
cout << "                             | 2. Satýþ listesi                                              |" << endl; // Sebze ve meyvelerin müþteriye satýlma fiyatlarý
cout << "                             | 3. Alýþ listesi                                               |" << endl; // Sebze ve meyvelerin üçüncü partiden alýnma maliyetleri
cout << "                             | 4. Stok listesi                                               |" << endl; // "Kontrol"lü stoktaki sebze ve meyve miktarlarý
cout << "                             | 5. Kazanç listesi                                             |" << endl; // Manav'ýn kazanç listesinin sýfýrlanmasýnýdan itibarenki toplam kazancý (Meyve baþýna dahil)
cout << "                             |                                                               |" << endl;
cout << "                             | 6. Satýþ listesini manuel olarak güncelleme                   |" << endl; // Sebze ve meyvelerin müþteriye satýþ miktarlarýnýn güncellenmesi
cout << "                             | 7. Alýþ listesini manuel olarak güncelleme                    |" << endl; // Sebze ve meyvelerin müþteriye üçüncü partiden alýnma maliyetlerinin güncellenmesi
cout << "                             | 8. Stoktaki ürün miktarýný manuel olarak güncelleme           |" << endl; // Stoktaki sebze ve meyvelerin miktarlarýnýn güncellenmesi
cout << "                             |                                                               |" << endl;
cout << "                             | 9. Ayarlar                                                    |" << endl; // "Kontrol"ü ayarlama
cout << "                             | 10.Kayýt sýfýrlama menüsü                                     |" << endl; // "Little Boy"
cout << "                             *****************************************************************" << endl;
cin >> secim;
system ( "cls" );
switch(secim)
 {
  case 1:
   {
    hesapla(fiyat,stok,alis,kazanc); 
    cout << "Toplam fiyat : " << toplamfiyat << " TL" << endl;
    toplamfiyat = 0;
    break;
   }
  case 2:
   {
   fiyatliste(fiyat);
   break;
   }
  case 3:
   {
   alisliste(alis);
   break;
   }
  case 4:
   {
   stokliste(stok);
   break;
   }
  case 5:
   {
   kazancliste(kazanc);
   break;
   }  
  case 6: 
   {
    guncelle(fiyat);
    break;
   }
  case 7: 
   {
    guncelle2(alis);
    break;
   }
  case 8:
   {
   depo(stok);
   break;
   }
  case 9:
   {
   guncelle5();
   break;
   }
  case 10:
   {
   sifirlamamenu(fiyat,alis,stok,kazanc);
   break;
   }    
 }
  cout << "*****************************************************************" << endl;
  cout << "| Ana menüye dönmek istermisiniz?[E/H]" << endl;
  cin.ignore();
  cin >> tekrar;
  system ( "cls" );
}
 system("pause");
 return 0;
}


 //Ayarlar

float guncelle5()
{
ifstream oku5("ayarlar.txt");
oku5 >> minmaks >> minn >> maks >> maksmaks;


  while((tekrar != 'H') && (tekrar != 'h'))
  {
      cout << "-----------------------------------------------------------------" << endl;
      cout << "| 1:  Stok minimum ayarý " << minn << endl;                                                  //Stok miktarýnýn ideal minimum miktarý
      cout << "| 2:  Stok maksimum ayarý " << maks << endl;                                                 //Stok miktarýnýn ideal maksimum miktarý
      cout << "| 3:       Stok kritik minimum ayarý " << minmaks << endl;                                   //Stok miktarýnýn kritik minimum miktarý
      cout << "| 4:       Stok kritik maksimum ayarý " << maksmaks << endl;                                 //Stok miktarýnýn kritik maksimum miktarý
      cout << "| 0:  Vazgeç" << endl;                                                                       // -... ..- -. .-.. .- .-. -.-. --- -.- -.- .- .-. .. ... .. -.- --. . .-.. -.. .. -... .- -. .- -... .- -.-- -... .- -.-- 
      cout << "-----------------------------------------------------------------" << endl; 
      cout << "|Güncellemek istediðiniz ayarýn numarasýný giriniz." << endl;
      cout << "| ";
      cin >> secim2;
      cout << "-----------------------------------------------------------------" << endl;
  switch(secim2)
  {
  case 1: 
   {
    cout << "Yeni minimum'u giriniz" << endl;
    cin >> minn; 
    break;       
   }    
  case 2: 
   {
    cout << "Yeni maksimum'u giriniz" << endl;
    cin >> maks; 
    break;       
   }
  case 3: 
   {
    cout << "Yeni kritik minimum'u giriniz" << endl;
    cin >> minmaks; 
    break;       
   }
  case 4: 
   {
    cout << "Yeni kritik maksimum'u giriniz" << endl;
    cin >> maksmaks; 
    break;       
   }
  default: 
   { 
    break;       
   }
  }
  cout << "*****************************************************************" << endl;
  cout << "| Daha fazla secmek istermisiniz?[E/H]" << endl;
  cin.ignore();
  cin >> tekrar;
  } 
  ofstream yaz5("ayarlar.txt");
 yaz5 << minmaks << " " << minn << " " <<  maks << " " << maksmaks << " ";
}

//Sýfýrlama menüsü

void sifirlamamenu(urunler& fiyat, urunler& alis, urunler& stok, urunler& kazanc)
 {
    cout << "                             *****************************************************************" << endl;
    cout << "                             |                                                               |" << endl;
    cout << "                             |                          Fonksiyonlar:                        |" << endl; // -.-. .. -. / -.- . -. -.. .. -.- . -. -.. .. -. . -.- --- -.. -.-- .- --.. .- -... .. .-.. . -. -.-- .- .--. .- -.-- --.. . -.- .- -.-- .. -.-. .- .-.. .. ... - .. .-.
    cout << "                             |                                                               |" << endl;
    cout << "                             |                                                               |" << endl;
    cout << "                             | 1. Satýþ listesini sýfýrlama                                  |" << endl; // Satýþ listesinin bütün verilerine 0 deðerini ata
    cout << "                             |                                                               |" << endl;
    cout << "                             |                                  2. Alýþ listesini sýfýrlama  |" << endl; // Alýþ listesinin bütün verilerine 0 deðerini ata
    cout << "                             |                                                               |" << endl;
    cout << "                             | 3. Stoktaki ürün miktarýný sýfýrlama                          |" << endl; // Stok listesinin bütün verilerine 0 deðerini ata
    cout << "                             |                                                               |" << endl;
    cout << "                             |                                  4. Kazanç listesini sýfýrlama|" << endl; // Kazanç listesinin bütün verilerine 0 deðerini ata
    cout << "                             |                                                               |" << endl;
    cout << "                             | 5.Ayarlarý sýfýrlama                                          |" << endl; // Ayarlarýn bütün verilerine 0 deðerini ata
    cout << "                             |                                                               |" << endl;
    cout << "                             |                                                               |" << endl;
    cout << "                             | 0. Vazgeç                                                     |" << endl;
    cout << "                             *****************************************************************" << endl;
    cin >> secim2;
    switch(secim2)
     {
      case 1:
       {
        system("del fiyatlistesi.txt");
        fiyatsifirla(fiyat);
        cout << "| Satýþ listesi baþarýyla sýfýrlandý! |" << endl;    
        break;
       }
      case 2:
       {
         system("del alislistesi.txt");
         alissifirla(alis);
         cout << "| Alýþ listesi baþarýyla sýfýrlandý! |" << endl;
         break;   
       } 
      case 3:
       {
        system("del stoklistesi.txt");
        stoksifirla(stok);
        cout << "| Stok listesi baþarýyla sýfýrlandý! |" << endl; 
        break;   
       } 
      case 4:
       {
        system("del kazanclistesi.txt");
        kazancsifirla(kazanc);
        cout << "| Kazanç listesi baþarýyla sýfýrlandý! |" << endl; 
        break;   
       } 
      case 5:
       {
         system("del ayarlar.txt");
         ayarlarsifirla();
         cout << "| Ayarlar baþarýyla sýfýrlandý! |" << endl; 
         break;  
       }
      default:
      {
      break;
      }     
   }        
}


//Alýþveriþ iþlemleri
float hesapla(urunler& fiyat, urunler& stok, urunler& alis, urunler& kazanc)
{
  ifstream oku("fiyatlistesi.txt");
oku >> fiyat.mantar >> fiyat.patates >> fiyat.sogan >>  fiyat.domates >>  fiyat.patlican >> fiyat.havuc >> fiyat.biber >> fiyat.salatalik
>> fiyat.limon >> fiyat.fasulye >> fiyat.kabak >> fiyat.sarimsak >> fiyat.lahana >> fiyat.pirasa >> fiyat.brokoli >> fiyat.muz 
>> fiyat.silor >> fiyat.turp >> fiyat.ispanak >> fiyat.kereviz >> fiyat.karnabahar >> fiyat.semizotu >> fiyat.lahana >> fiyat.kabak >> fiyat.portakal 
>> fiyat.cilek >> fiyat.erik >> fiyat.elma >> fiyat.karpuz >> fiyat.kavun >> fiyat.armut >> fiyat.mandalina >> fiyat.kivi >> fiyat.uzum 
>> fiyat.nektarin >> fiyat.nar >> fiyat.avakado >> fiyat.seftali >> fiyat.greyfurt;

ifstream oku2("alislistesi.txt");
oku2 >> alis.mantar >> alis.patates >> alis.sogan >>  alis.domates >>  alis.patlican >> alis.havuc >> alis.biber >> alis.salatalik
>> alis.limon >> alis.fasulye >> alis.kabak >> alis.sarimsak >> alis.lahana >> alis.pirasa >> alis.brokoli >> alis.muz 
>> alis.silor >> alis.turp >> alis.ispanak >> alis.kereviz >> alis.karnabahar >> alis.semizotu >> alis.lahana >> alis.kabak >> alis.portakal 
>> alis.cilek >> alis.erik >> alis.elma >> alis.karpuz >> alis.kavun >> alis.armut >> alis.mandalina >> alis.kivi >> alis.uzum 
>> alis.nektarin >> alis.nar >> alis.avakado >> alis.seftali >> alis.greyfurt;

  ifstream oku3("stoklistesi.txt");
oku3 >> stok.mantar >> stok.patates >> stok.sogan >>  stok.domates >>  stok.patlican >> stok.havuc >> stok.biber >> stok.salatalik
>> stok.limon >> stok.fasulye >> stok.kabak >> stok.sarimsak >> stok.lahana >> stok.pirasa >> stok.brokoli >> stok.muz 
>> stok.silor >> stok.turp >> stok.ispanak >> stok.kereviz >> stok.karnabahar >> stok.semizotu >> stok.lahana >> stok.kabak >> stok.portakal 
>> stok.cilek >> stok.erik >> stok.elma >> stok.karpuz >> stok.kavun >> stok.armut >> stok.mandalina >> stok.kivi >> stok.uzum 
>> stok.nektarin >> stok.nar >> stok.avakado >> stok.seftali >> stok.greyfurt;

 ifstream oku4("kazanclistesi.txt");
oku4 >> kazanc.mantar >> kazanc.patates >> kazanc.sogan >>  kazanc.domates >>  kazanc.patlican >> kazanc.havuc >> kazanc.biber >> kazanc.salatalik
>> kazanc.limon >> kazanc.fasulye >> kazanc.kabak >> kazanc.sarimsak >> kazanc.lahana >> kazanc.pirasa >> kazanc.brokoli >> kazanc.muz 
>> kazanc.silor >> kazanc.turp >> kazanc.ispanak >> kazanc.kereviz >> kazanc.karnabahar >> kazanc.semizotu >> kazanc.lahana >> kazanc.kabak >> kazanc.portakal 
>> kazanc.cilek >> kazanc.erik >> kazanc.elma >> kazanc.karpuz >> kazanc.kavun >> kazanc.armut >> kazanc.mandalina >> kazanc.kivi >> kazanc.uzum 
>> kazanc.nektarin >> kazanc.nar >> kazanc.avakado >> kazanc.seftali >> kazanc.greyfurt;
 ifstream oku5("ayarlar.txt");
oku5 >> minmaks >> minn >> maks >> maksmaks;



  while((tekrar != 'H') && (tekrar != 'h'))
   {
    cout << "*****************************************************************" << endl;
    cout << "| Sebze(S) <------------------   ------------------> Meyve(M)" << endl;
    cout << "| Girmek istediðiniz ürün türünü seçiniz." << endl; 
    istek = getch();
    if((istek == 'S') || (istek == 's'))
     {
      cout << "*****************************************************************" << endl;
      cout << "| 1: " << s1 << " kilosu " << fiyat.mantar << " TL ve" << " Stokta " << stok.mantar  << " tane var."<< endl;
      cout << "| 2: " << s2 << " kilosu " << fiyat.patates << " TL ve" << " Stokta " << stok.patates  << " tane var."<< endl;
      cout << "| 3: " << s3 << " kilosu " << fiyat.sogan << " TL ve" << " Stokta " << stok.sogan  << " tane var."<< endl;
      cout << "| 4: " << s4 << " kilosu " << fiyat.domates << " TL ve" << " Stokta " << stok.domates  << " tane var."<< endl;
      cout << "| 5: " << s5 << " kilosu " << fiyat.patlican << " TL ve" << " Stokta " << stok.patlican  << " tane var."<< endl;
      cout << "| 6: " << s6 << " kilosu " << fiyat.havuc << " TL ve" << " Stokta " << stok.havuc  << " tane var."<< endl;
      cout << "| 7: " << s7 << " kilosu " << fiyat.biber << " TL ve" << " Stokta " << stok.biber  << " tane var."<< endl;
      cout << "| 8: " << s8 << " kilosu " << fiyat.salatalik << " TL ve" << " Stokta " << stok.salatalik  << " tane var."<< endl;
      cout << "| 9: " << s9 << " kilosu " << fiyat.limon << " TL ve" << " Stokta " << stok.limon  << " tane var."<< endl;
      cout << "| 10: " << s10 << " kilosu " << fiyat.fasulye << " TL ve" << " Stokta " << stok.fasulye  << " tane var."<< endl;
      cout << "| 11: " << s11 << " kilosu " << fiyat.kabak << " TL ve" << " Stokta " << stok.kabak  << " tane var."<< endl;
      cout << "| 12: " << s12 << " kilosu " << fiyat.sarimsak << " TL ve" << " Stokta " << stok.sarimsak  << " tane var."<< endl;
      cout << "| 13: " << s13 << " kilosu " << fiyat.lahana << " TL ve" << " Stokta " << stok.lahana  << " tane var."<< endl;
      cout << "| 14: " << s14 << " kilosu " << fiyat.pirasa << " TL ve" << " Stokta " << stok.pirasa  << " tane var."<< endl;
      cout << "| 15: " << s15 << " kilosu " << fiyat.brokoli << " TL ve" << " Stokta " << stok.brokoli  << " tane var."<< endl;
      cout << "| 16: " << s16 << " kilosu " << fiyat.muz << " TL ve" << " Stokta " << stok.muz  << " tane var."<< endl;
      cout << "| 17: " << s17 << " kilosu " << fiyat.silor << " TL ve" << " Stokta " << stok.silor  << " tane var."<< endl;
      cout << "| 18: " << s18 << " kilosu " << fiyat.turp << " TL ve" << " Stokta " << stok.turp  << " tane var."<< endl;
      cout << "| 19: " << s19 << " kilosu " << fiyat.ispanak << " TL ve" << " Stokta " << stok.ispanak  << " tane var."<< endl;
      cout << "| 20: " << s20 << " kilosu " << fiyat.kereviz << " TL ve" << " Stokta " << stok.kereviz  << " tane var."<< endl;
      cout << "| 21: " << s21 << " kilosu " << fiyat.karnabahar << " TL ve" << " Stokta " << stok.karnabahar  << " tane var."<< endl;
      cout << "| 22: " << s22 << " kilosu " << fiyat.semizotu << " TL ve" << " Stokta " << stok.semizotu  << " tane var."<< endl;
      cout << "| 23: " << s23 << " kilosu " << fiyat.lahana << " TL ve" << " Stokta " << stok.lahana  << " tane var."<< endl;
      cout << "| 0:   Vazgeç " << endl;
      cout << "*****************************************************************" << endl;
      cout << "| Sebzenin numarasýný seçiniz" << endl;
      cout << "| ";
      cin >> urun;
      cout << "*****************************************************************" << endl;
       
      switch(urun)
       {
        case 1:
         {
          cout << "Hesaplamak istediðiniz " << s1 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.mantar - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.mantar;
          kazanc.mantar += kilo*(fiyat.mantar - alis.mantar);
          stok.mantar -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s1 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;  
         }   
        case 2:
         {
          cout << "Hesaplamak istediðiniz " << s2 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.patates - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.patates;
          kazanc.patates += kilo*(fiyat.patates - alis.patates);
          stok.patates -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s2 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;    
         }   
        case 3:
         {
          cout << "Hesaplamak istediðiniz " << s3 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.sogan - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.sogan;
          kazanc.sogan += kilo*(fiyat.sogan - alis.sogan);
          stok.sogan -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s3 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;  
         }   
        case 4:
         {
          cout << "Hesaplamak istediðiniz " << s4 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.domates - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.domates;
          kazanc.domates += kilo*(fiyat.domates - alis.domates);
          stok.domates -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s4 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;              
         }   
        case 5:
         {
          cout << "Hesaplamak istediðiniz " << s5 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.patlican - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.patlican;
          kazanc.patlican += kilo*(fiyat.patlican - alis.patlican);
          stok.patlican -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s5 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;               
         }   
        case 6:
         {
          cout << "Hesaplamak istediðiniz " << s6 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.havuc - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.havuc;
          kazanc.havuc += kilo*(fiyat.havuc - alis.havuc);
          stok.havuc -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s6 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;               
         }   
        case 7:
         {
          cout << "Hesaplamak istediðiniz " << s7 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.biber - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.biber;
          kazanc.biber += kilo*(fiyat.biber - alis.biber);
          stok.biber -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s7 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;               
         }   
        case 8:
         {
          cout << "Hesaplamak istediðiniz " << s8 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.salatalik - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.salatalik;
          kazanc.salatalik += kilo*(fiyat.salatalik - alis.salatalik);
          stok.salatalik -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s8 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;              
         }   
        case 9:
         {
          cout << "Hesaplamak istediðiniz " << s9 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.limon - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.limon;
          kazanc.limon += kilo*(fiyat.limon - alis.limon);
          stok.limon -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s9 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;              
         }   
        case 10:
         {
          cout << "Hesaplamak istediðiniz " << s10 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.fasulye - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.fasulye;
          kazanc.fasulye += kilo*(fiyat.fasulye - alis.fasulye);
          stok.fasulye -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s10 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;               
         }   
         case 11:
         {
          cout << "Hesaplamak istediðiniz " << s11 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.kabak - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.kabak;
          kazanc.kabak += kilo*(fiyat.kabak - alis.kabak);
          stok.kabak -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s11 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;             
         }   
        case 12:
         {
          cout << "Hesaplamak istediðiniz " << s12 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.sarimsak - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.sarimsak;
          kazanc.sarimsak += kilo*(fiyat.sarimsak - alis.sarimsak);
          stok.sarimsak -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s12 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;             
         }   
        case 13:
         {
          cout << "Hesaplamak istediðiniz " << s13 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.lahana - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.lahana;
          kazanc.lahana += kilo*(fiyat.lahana - alis.lahana);
          stok.lahana -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s13 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;           
         }   
        case 14:
         {
          cout << "Hesaplamak istediðiniz " << s14 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.pirasa - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.pirasa;
          kazanc.pirasa += kilo*(fiyat.pirasa - alis.pirasa);
          stok.pirasa -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s14 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;               
         }   
        case 15:
         {
          cout << "Hesaplamak istediðiniz " << s15 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.brokoli - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.brokoli;
          kazanc.brokoli += kilo*(fiyat.brokoli - alis.brokoli);
          stok.brokoli -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s15 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;             
         }   
        case 16:
         {
          cout << "Hesaplamak istediðiniz " << s16 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.muz - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.muz;
          kazanc.muz += kilo*(fiyat.muz - alis.muz);
          stok.muz -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s16 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;               
         }   
        case 17:
         {
          cout << "Hesaplamak istediðiniz " << s17 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.silor - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.silor;
          kazanc.silor += kilo*(fiyat.silor - alis.silor);
          stok.silor -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s17 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;             
         }   
        case 18:
         {
          cout << "Hesaplamak istediðiniz " << s18 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.turp - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.turp;
          kazanc.turp += kilo*(fiyat.turp - alis.turp);
          stok.turp -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s18 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;              
         }   
        case 19:
         {
          cout << "Hesaplamak istediðiniz " << s19 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.ispanak - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.ispanak;
          kazanc.ispanak += kilo*(fiyat.ispanak - alis.ispanak);
          stok.ispanak -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s19 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;              
         }   
        case 20:
         {
          cout << "Hesaplamak istediðiniz " << s20 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.kereviz - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.kereviz;
          kazanc.kereviz += kilo*(fiyat.kereviz - alis.kereviz);
          stok.kereviz -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s20 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;              
         }
        case 21:
         {
          cout << "Hesaplamak istediðiniz " << s21 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.karnabahar - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.karnabahar;
          kazanc.karnabahar += kilo*(fiyat.karnabahar - alis.karnabahar);
          stok.karnabahar -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s21 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;           
         }   
        case 22:
         {
          cout << "Hesaplamak istediðiniz " << s22 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.semizotu - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.semizotu;
          kazanc.semizotu += kilo*(fiyat.semizotu - alis.semizotu);
          stok.semizotu -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s22 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;            
         }   
        case 23:
         {
          cout << "Hesaplamak istediðiniz " << s23 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.lahana - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.lahana;
          kazanc.lahana += kilo*(fiyat.lahana - alis.lahana);
          stok.lahana -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << s23 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;
         default:
          {
           break;
          }                  
         }       
       }
     }    
      
    if((istek == 'M') || (istek == 'm'))  
     {
      cout << "*****************************************************************" << endl;
      cout << "| 1: " << m1 << " kilosu " << fiyat.portakal << " TL ve" << " Stokta " << stok.portakal  << " tane var."<< endl;
      cout << "| 2: " << m2 << " kilosu " << fiyat.cilek << " TL ve" << " Stokta " << stok.cilek  << " tane var."<< endl;
      cout << "| 3: " << m3 << " kilosu " << fiyat.erik << " TL ve" << " Stokta " << stok.erik  << " tane var."<< endl;
      cout << "| 4: " << m4 << " kilosu " << fiyat.elma << " TL ve" << " Stokta " << stok.elma  << " tane var."<< endl;
      cout << "| 5: " << m5 << " kilosu " << fiyat.karpuz << " TL ve" << " Stokta " << stok.karpuz  << " tane var."<< endl;
      cout << "| 6: " << m6 << " kilosu " << fiyat.kavun << " TL ve" << " Stokta " << stok.kavun  << " tane var."<< endl;
      cout << "| 7: " << m7 << " kilosu " << fiyat.armut << " TL ve" << " Stokta " << stok.armut  << " tane var."<< endl;
      cout << "| 8: " << m8 << " kilosu " << fiyat.mandalina << " TL ve" << " Stokta " << stok.mandalina  << " tane var."<< endl;
      cout << "| 9: " << m9 << " kilosu " << fiyat.kivi << " TL ve" << " Stokta " << stok.kivi  << " tane var."<< endl;
      cout << "| 10: " << m10 << " kilosu " << fiyat.uzum << " TL ve" << " Stokta " << stok.uzum  << " tane var."<< endl;
      cout << "| 11: " << m11 << " kilosu " << fiyat.nektarin << " TL ve" << " Stokta " << stok.nektarin  << " tane var."<< endl;
      cout << "| 12: " << m12 << " kilosu " << fiyat.nar << " TL ve" << " Stokta " << stok.nar  << " tane var."<< endl;
      cout << "| 13: " << m13 << " kilosu " << fiyat.avakado << " TL ve" << " Stokta " << stok.avakado  << " tane var."<< endl;
      cout << "| 14: " << m14 << " kilosu " << fiyat.seftali << " TL ve" << " Stokta " << stok.seftali  << " tane var."<< endl;
      cout << "| 15: " << m15 << " kilosu " << fiyat.greyfurt << " TL ve" << " Stokta " << stok.greyfurt  << " tane var."<< endl;
      cout << "| 0:   Vazgeç " << endl;
      cout << "*****************************************************************" << endl; 
      cout << "| Meyvenin numarasýný seçiniz" << endl;
      cout << "| ";
      cin >> urun;
      cout << "*****************************************************************" << endl;
      switch(urun)
       {
        case 1:
         {
          cout << "Hesaplamak istediðiniz " << m1 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.portakal - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.portakal;
          kazanc.portakal += kilo*(fiyat.portakal - alis.portakal);
          stok.portakal -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << m1 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;             
         }   
        case 2:
         {
          cout << "Hesaplamak istediðiniz " << m2 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.cilek - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.cilek;
          kazanc.cilek += kilo*(fiyat.cilek - alis.cilek);
          stok.cilek -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << m2 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;             
         }   
        case 3:
         {
          cout << "Hesaplamak istediðiniz " << m3 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.erik - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.erik;
          kazanc.erik += kilo*(fiyat.erik - alis.erik);
          stok.erik -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << m3 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;             
         }   
        case 4:
         {
          cout << "Hesaplamak istediðiniz " << m4 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.elma - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.elma;
          kazanc.elma += kilo*(fiyat.elma - alis.elma);
          stok.elma -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << m4 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;              
         }   
        case 5:
         {
          cout << "Hesaplamak istediðiniz " << m5 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.karpuz - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.karpuz;
          kazanc.karpuz += kilo*(fiyat.karpuz - alis.karpuz);
          stok.karpuz -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << m5 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;              
         }   
        case 6:
         {
          cout << "Hesaplamak istediðiniz " << m6 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.kavun - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.kavun;
          kazanc.kavun += kilo*(fiyat.kavun - alis.kavun);
          stok.kavun -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << m6 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;              
         }   
        case 7:
         {
          cout << "Hesaplamak istediðiniz " << m7 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.armut - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.armut;
          kazanc.armut += kilo*(fiyat.armut - alis.armut);
          stok.armut -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << m7 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;              
         }  
        case 8:
         {
          cout << "Hesaplamak istediðiniz " << m8 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.mandalina - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.mandalina;
          kazanc.mandalina += kilo*(fiyat.mandalina - alis.mandalina);
          stok.mandalina -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << m8 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;              
         }   
        case 9:
         {
          cout << "Hesaplamak istediðiniz " << m9 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.kivi - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.kivi;
          kazanc.kivi += kilo*(fiyat.kivi - alis.kivi);
          stok.kivi -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << m9 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;           
         }   
        case 10:
         {
          cout << "Hesaplamak istediðiniz " << m10 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.uzum - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.uzum;
          kazanc.uzum += kilo*(fiyat.uzum - alis.uzum);
          stok.uzum -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << m10 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;               
         }   
        case 11:
         {
          cout << "Hesaplamak istediðiniz " << m11 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.nektarin - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.nektarin;
          kazanc.nektarin += kilo*(fiyat.nektarin - alis.nektarin);
          stok.nektarin -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << m11 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;              
         }   
        case 12:
         {
          cout << "Hesaplamak istediðiniz " << m12 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.nar - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.nar;
          kazanc.nar += kilo*(fiyat.nar - alis.nar);
          stok.nar -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << m12 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;              
         }   
        case 13:
         {
          cout << "Hesaplamak istediðiniz " << m13 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.avakado - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.avakado;
          kazanc.avakado += kilo*(fiyat.avakado - alis.avakado);
          stok.avakado -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << m13 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;              
         }   
        case 14:
         {
          cout << "Hesaplamak istediðiniz " << m14 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.seftali - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.seftali;
          kazanc.seftali += kilo*(fiyat.seftali - alis.seftali);
          stok.seftali -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << m14 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;             
         }  
        case 15:
         {
          cout << "Hesaplamak istediðiniz " << m15 << " miktari(kilo)?" << endl;
          cin >> kilo;
          if((stok.greyfurt - kilo) >= 0)
          {
          toplamfiyat += kilo * fiyat.greyfurt;
          kazanc.greyfurt += kilo*(fiyat.greyfurt - alis.greyfurt);
          stok.greyfurt -= kilo;
          }
          else 
          {
          SetConsoleTextAttribute(hConsole, 252);
          cout << "Ýstenilen miktarda " << m15 << " kalmamýþ, iþleminiz gerçekleþtirilemiyor." << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
          }    
          break;             
         }
        default:
          {
           break;
          }      
       }
      }
    cout << "*****************************************************************" << endl;
    cout << "| Daha fazla secmek istermisiniz?[E/H]" << endl;
    cin.ignore();
    cin >> tekrar;
    cout << "*****************************************************************" << endl;
   }
  ofstream yaz("fiyatlistesi.txt");
 yaz << fiyat.mantar << " " << fiyat.patates << " " << fiyat.sogan << " " << fiyat.domates << " " << fiyat.patlican << " " << fiyat.havuc << " " << fiyat.biber << " " << fiyat.salatalik << " "
 << fiyat.limon << " " << fiyat.fasulye << " " << fiyat.kabak << " " << fiyat.sarimsak << " " << fiyat.lahana << " " << fiyat.pirasa << " " << fiyat.brokoli << " " << fiyat.muz << " "
 << fiyat.silor << " " << fiyat.turp <<  " " << fiyat.ispanak << " " << fiyat.kereviz << " " << fiyat.karnabahar << " " << fiyat.semizotu << " " << fiyat.lahana << " " << fiyat.kabak << " " << fiyat.portakal << " "
 << fiyat.cilek << " " << fiyat.erik << " " << fiyat.elma << " " << fiyat.karpuz << " " << fiyat.kavun << " " << fiyat.armut << " " << fiyat.mandalina << " " << fiyat.kivi << " " << fiyat.uzum << " "
 << fiyat.nektarin << " " << fiyat.nar << " " << fiyat.avakado << " " << fiyat.seftali << " " << fiyat.greyfurt << " ";

  ofstream yaz2("alislistesi.txt");
 yaz2 << alis.mantar << " " << alis.patates << " " << alis.sogan << " " << alis.domates << " " << alis.patlican << " " << alis.havuc << " " << alis.biber << " " << alis.salatalik << " "
 << alis.limon << " " << alis.fasulye << " " << alis.kabak << " " << alis.sarimsak << " " << alis.lahana << " " << alis.pirasa << " " << alis.brokoli << " " << alis.muz << " "
 << alis.silor << " " << alis.turp <<  " " << alis.ispanak << " " << alis.kereviz << " " << alis.karnabahar << " " << alis.semizotu << " " << alis.lahana << " " << alis.kabak << " " << alis.portakal << " "
 << alis.cilek << " " << alis.erik << " " << alis.elma << " " << alis.karpuz << " " << alis.kavun << " " << alis.armut << " " << alis.mandalina << " " << alis.kivi << " " << alis.uzum << " "
 << alis.nektarin << " " << alis.nar << " " << alis.avakado << " " << alis.seftali << " " << alis.greyfurt << " ";
   
    ofstream yaz3("stoklistesi.txt");
 yaz3 << stok.mantar << " " << stok.patates << " " << stok.sogan << " " << stok.domates << " " << stok.patlican << " " << stok.havuc << " " << stok.biber << " " << stok.salatalik << " "
 << stok.limon << " " << stok.fasulye << " " << stok.kabak << " " << stok.sarimsak << " " << stok.lahana << " " << stok.pirasa << " " << stok.brokoli << " " << stok.muz << " "
 << stok.silor << " " << stok.turp <<  " " << stok.ispanak << " " << stok.kereviz << " " << stok.karnabahar << " " << stok.semizotu << " " << stok.lahana << " " << stok.kabak << " " << stok.portakal << " "
 << stok.cilek << " " << stok.erik << " " << stok.elma << " " << stok.karpuz << " " << stok.kavun << " " << stok.armut << " " << stok.mandalina << " " << stok.kivi << " " << stok.uzum << " "
 << stok.nektarin << " " << stok.nar << " " << stok.avakado << " " << stok.seftali << " " << stok.greyfurt << " "; 
   
   ofstream yaz4("kazanclistesi.txt");
   yaz4 << kazanc.mantar << " " << kazanc.patates << " " << kazanc.sogan << " " << kazanc.domates << " " << kazanc.patlican << " " << kazanc.havuc << " " << kazanc.biber << " " << kazanc.salatalik << " "
 << kazanc.limon << " " << kazanc.fasulye << " " << kazanc.kabak << " " << kazanc.sarimsak << " " << kazanc.lahana << " " << kazanc.pirasa << " " << kazanc.brokoli << " " << kazanc.muz << " "
 << kazanc.silor << " " << kazanc.turp <<  " " << kazanc.ispanak << " " << kazanc.kereviz << " " << kazanc.karnabahar << " " << kazanc.semizotu << " " << kazanc.lahana << " " << kazanc.kabak << " " << kazanc.portakal << " "
 << kazanc.cilek << " " << kazanc.erik << " " << kazanc.elma << " " << kazanc.karpuz << " " << kazanc.kavun << " " << kazanc.armut << " " << kazanc.mandalina << " " << kazanc.kivi << " " << kazanc.uzum << " "
 << kazanc.nektarin << " " << kazanc.nar << " " << kazanc.avakado << " " << kazanc.seftali << " " << kazanc.greyfurt << " ";
}

//Satýþ listesi

void fiyatliste(urunler& fiyat)
{
  ifstream oku("fiyatlistesi.txt");
oku >> fiyat.mantar >> fiyat.patates >> fiyat.sogan >>  fiyat.domates >>  fiyat.patlican >> fiyat.havuc >> fiyat.biber >> fiyat.salatalik
>> fiyat.limon >> fiyat.fasulye >> fiyat.kabak >> fiyat.sarimsak >> fiyat.lahana >> fiyat.pirasa >> fiyat.brokoli >> fiyat.muz 
>> fiyat.silor >> fiyat.turp >> fiyat.ispanak >> fiyat.kereviz >> fiyat.karnabahar >> fiyat.semizotu >> fiyat.lahana >> fiyat.kabak >> fiyat.portakal 
>> fiyat.cilek >> fiyat.erik >> fiyat.elma >> fiyat.karpuz >> fiyat.kavun >> fiyat.armut >> fiyat.mandalina >> fiyat.kivi >> fiyat.uzum 
>> fiyat.nektarin >> fiyat.nar >> fiyat.avakado >> fiyat.seftali >> fiyat.greyfurt;

      cout << "                                     ***************************************************" << endl;
      cout << "                                     | 1: " << s1 << " kilosu " << fiyat.mantar << " TL" << endl;
      cout << "                                     | 2: " << s2 << " kilosu " << fiyat.patates << " TL" << endl;
      cout << "                                     | 3: " << s3 << " kilosu " << fiyat.sogan << " TL" << endl;
      cout << "                                     | 4: " << s4 << " kilosu " << fiyat.domates << " TL" << endl;
      cout << "                                     | 5: " << s5 << " kilosu " << fiyat.patlican << " TL" << endl;
      cout << "                                     | 6: " << s6 << " kilosu " << fiyat.havuc << " TL" << endl;
      cout << "                                     | 7: " << s7 << " kilosu " << fiyat.biber << " TL" << endl;
      cout << "                                     | 8: " << s8 << " kilosu " << fiyat.salatalik << " TL" << endl;
      cout << "                                     | 9: " << s9 << " kilosu " << fiyat.limon << " TL" << endl;
      cout << "                                     | 10: " << s10 << " kilosu " << fiyat.fasulye << " TL" << endl;
      cout << "                                     | 11: " << s11 << " kilosu " << fiyat.kabak << " TL" << endl;
      cout << "                                     | 12: " << s12 << " kilosu " << fiyat.sarimsak << " TL" << endl;
      cout << "                                     | 13: " << s13 << " kilosu " << fiyat.lahana << " TL" << endl;
      cout << "                                     | 14: " << s14 << " kilosu " << fiyat.pirasa << " TL" << endl;
      cout << "                                     | 15: " << s15 << " kilosu " << fiyat.brokoli << " TL" << endl;
      cout << "                                     | 16: " << s16 << " kilosu " << fiyat.muz << " TL" << endl;
      cout << "                                     | 17: " << s17 << " kilosu " << fiyat.silor << " TL" << endl;
      cout << "                                     | 18: " << s18 << " kilosu " << fiyat.turp << " TL" << endl;
      cout << "                                     | 19: " << s19 << " kilosu " << fiyat.ispanak << " TL" << endl;
      cout << "                                     | 20: " << s20 << " kilosu " << fiyat.kereviz << " TL" << endl;
      cout << "                                     | 21: " << s21 << " kilosu " << fiyat.karnabahar << " TL" << endl;
      cout << "                                     | 22: " << s22 << " kilosu " << fiyat.semizotu << " TL" << endl;
      cout << "                                     | 23: " << s23 << " kilosu " << fiyat.lahana << " TL" << endl;
      cout << "                                     | 24: " << m1 << " kilosu " << fiyat.portakal << " TL" << endl;
      cout << "                                     | 25: " << m2 << " kilosu " << fiyat.cilek << " TL" << endl;
      cout << "                                     | 26: " << m3 << " kilosu " << fiyat.erik << " TL" << endl;
      cout << "                                     | 27: " << m4 << " kilosu " << fiyat.elma << " TL" << endl;
      cout << "                                     | 28: " << m5 << " kilosu " << fiyat.karpuz << " TL" << endl; 
      cout << "                                     | 29: " << m6 << " kilosu " << fiyat.kavun << " TL" << endl;
      cout << "                                     | 30: " << m7 << " kilosu " << fiyat.armut << " TL" << endl;
      cout << "                                     | 31: " << m8 << " kilosu " << fiyat.mandalina << " TL" << endl;
      cout << "                                     | 32: " << m9 << " kilosu " << fiyat.kivi << " TL" << endl;
      cout << "                                     | 33: " << m10 << " kilosu " << fiyat.uzum << " TL" << endl; 
      cout << "                                     | 34: " << m11 << " kilosu " << fiyat.nektarin << " TL" << endl;
      cout << "                                     | 35: " << m12 << " kilosu " << fiyat.nar << " TL" << endl;
      cout << "                                     | 36: " << m13 << " kilosu " << fiyat.avakado << " TL" << endl;
      cout << "                                     | 37: " << m14 << " kilosu " << fiyat.seftali << " TL" << endl;
      cout << "                                     | 38: " << m15 << " kilosu " << fiyat.greyfurt << " TL" << endl;
      cout << "                                     ***************************************************" << endl; 

}

//Alýþ listesi

void alisliste(urunler& alis)
{
ifstream oku2("alislistesi.txt");
oku2 >> alis.mantar >> alis.patates >> alis.sogan >>  alis.domates >>  alis.patlican >> alis.havuc >> alis.biber >> alis.salatalik
>> alis.limon >> alis.fasulye >> alis.kabak >> alis.sarimsak >> alis.lahana >> alis.pirasa >> alis.brokoli >> alis.muz 
>> alis.silor >> alis.turp >> alis.ispanak >> alis.kereviz >> alis.karnabahar >> alis.semizotu >> alis.lahana >> alis.kabak >> alis.portakal 
>> alis.cilek >> alis.erik >> alis.elma >> alis.karpuz >> alis.kavun >> alis.armut >> alis.mandalina >> alis.kivi >> alis.uzum 
>> alis.nektarin >> alis.nar >> alis.avakado >> alis.seftali >> alis.greyfurt;

      cout << "                                     ***************************************************" << endl;
      cout << "                                     | 1: " << s1 << " kilosu " << alis.mantar << " TL" << endl;
      cout << "                                     | 2: " << s2 << " kilosu " << alis.patates << " TL" << endl;
      cout << "                                     | 3: " << s3 << " kilosu " << alis.sogan << " TL" << endl;
      cout << "                                     | 4: " << s4 << " kilosu " << alis.domates << " TL" << endl;
      cout << "                                     | 5: " << s5 << " kilosu " << alis.patlican << " TL" << endl;
      cout << "                                     | 6: " << s6 << " kilosu " << alis.havuc << " TL" << endl;
      cout << "                                     | 7: " << s7 << " kilosu " << alis.biber << " TL" << endl;
      cout << "                                     | 8: " << s8 << " kilosu " << alis.salatalik << " TL" << endl;
      cout << "                                     | 9: " << s9 << " kilosu " << alis.limon << " TL" << endl;
      cout << "                                     | 10: " << s10 << " kilosu " << alis.fasulye << " TL" << endl;
      cout << "                                     | 11: " << s11 << " kilosu " << alis.kabak << " TL" << endl;
      cout << "                                     | 12: " << s12 << " kilosu " << alis.sarimsak << " TL" << endl;
      cout << "                                     | 13: " << s13 << " kilosu " << alis.lahana << " TL" << endl;
      cout << "                                     | 14: " << s14 << " kilosu " << alis.pirasa << " TL" << endl;
      cout << "                                     | 15: " << s15 << " kilosu " << alis.brokoli << " TL" << endl;
      cout << "                                     | 16: " << s16 << " kilosu " << alis.muz << " TL" << endl;
      cout << "                                     | 17: " << s17 << " kilosu " << alis.silor << " TL" << endl;
      cout << "                                     | 18: " << s18 << " kilosu " << alis.turp << " TL" << endl;
      cout << "                                     | 19: " << s19 << " kilosu " << alis.ispanak << " TL" << endl;
      cout << "                                     | 20: " << s20 << " kilosu " << alis.kereviz << " TL" << endl;
      cout << "                                     | 21: " << s21 << " kilosu " << alis.karnabahar << " TL" << endl;
      cout << "                                     | 22: " << s22 << " kilosu " << alis.semizotu << " TL" << endl;
      cout << "                                     | 23: " << s23 << " kilosu " << alis.lahana << " TL" << endl;
      cout << "                                     | 24: " << m1 << " kilosu " << alis.portakal << " TL" << endl;
      cout << "                                     | 25: " << m2 << " kilosu " << alis.cilek << " TL" << endl;
      cout << "                                     | 26: " << m3 << " kilosu " << alis.erik << " TL" << endl;
      cout << "                                     | 27: " << m4 << " kilosu " << alis.elma << " TL" << endl;
      cout << "                                     | 28: " << m5 << " kilosu " << alis.karpuz << " TL" << endl; 
      cout << "                                     | 29: " << m6 << " kilosu " << alis.kavun << " TL" << endl;
      cout << "                                     | 30: " << m7 << " kilosu " << alis.armut << " TL" << endl;
      cout << "                                     | 31: " << m8 << " kilosu " << alis.mandalina << " TL" << endl;
      cout << "                                     | 32: " << m9 << " kilosu " << alis.kivi << " TL" << endl;
      cout << "                                     | 33: " << m10 << " kilosu " << alis.uzum << " TL" << endl; 
      cout << "                                     | 34: " << m11 << " kilosu " << alis.nektarin << " TL" << endl;
      cout << "                                     | 35: " << m12 << " kilosu " << alis.nar << " TL" << endl;
      cout << "                                     | 36: " << m13 << " kilosu " << alis.avakado << " TL" << endl;
      cout << "                                     | 37: " << m14 << " kilosu " << alis.seftali << " TL" << endl;
      cout << "                                     | 38: " << m15 << " kilosu " << alis.greyfurt << " TL" << endl;
      cout << "                                     ***************************************************" << endl;

}

//Stok listesi

void stokliste(urunler& stok)
{
  ifstream oku3("stoklistesi.txt");
oku3 >> stok.mantar >> stok.patates >> stok.sogan >>  stok.domates >>  stok.patlican >> stok.havuc >> stok.biber >> stok.salatalik
>> stok.limon >> stok.fasulye >> stok.kabak >> stok.sarimsak >> stok.lahana >> stok.pirasa >> stok.brokoli >> stok.muz 
>> stok.silor >> stok.turp >> stok.ispanak >> stok.kereviz >> stok.karnabahar >> stok.semizotu >> stok.lahana >> stok.kabak >> stok.portakal 
>> stok.cilek >> stok.erik >> stok.elma >> stok.karpuz >> stok.kavun >> stok.armut >> stok.mandalina >> stok.kivi >> stok.uzum 
>> stok.nektarin >> stok.nar >> stok.avakado >> stok.seftali >> stok.greyfurt;

 ifstream oku5("ayarlar.txt");
oku5 >> minmaks >> minn >> maks >> maksmaks;

      cout << "                                     ***************************************************" << endl;
      cout << "                                     | 1: " << s1 << " stokta " << stok.mantar << " kilo var." << endl;
      
      if( ((minmaks < stok.mantar) && (stok.mantar <= minn)) || ((maksmaks > stok.mantar) && (stok.mantar >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s1 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.mantar <= minmaks) || (stok.mantar >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s1 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      cout << "                                     | 2: " << s2 << " stokta " << stok.patates << " kilo var." << endl;
       if( ((minmaks < stok.patates) && (stok.patates <= minn)) || ((maksmaks > stok.patates) && (stok.patates >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s2 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.patates <= minmaks) || (stok.patates >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s2 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 3: " << s3 << " stokta " << stok.sogan << " kilo var." << endl;
      if( ((minmaks < stok.sogan) && (stok.sogan <= minn)) || ((maksmaks > stok.sogan) && (stok.sogan >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s3 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.sogan <= minmaks) || (stok.sogan >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s3 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 4: " << s4 << " stokta " << stok.domates << "kilo var." << endl;
      if( ((minmaks < stok.domates) && (stok.domates <= minn)) || ((maksmaks > stok.domates) && (stok.domates >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s4 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.domates <= minmaks) || (stok.domates >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s4 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 5: " << s5 << " stokta " << stok.patlican << " kilo var." << endl;
      if( ((minmaks < stok.patlican) && (stok.patlican <= minn)) || ((maksmaks > stok.patlican) && (stok.patlican >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s5 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.patlican <= minmaks) || (stok.patlican >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s5 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 6: " << s6 << " stokta " << stok.havuc << " kilo var." << endl;
      if( ((minmaks < stok.havuc) && (stok.havuc <= minn)) || ((maksmaks > stok.havuc) && (stok.havuc >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s6 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.havuc <= minmaks) || (stok.havuc >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s6 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 7: " << s7 << " stokta " << stok.biber << " kilo var." << endl;
      if( ((minmaks < stok.biber) && (stok.biber <= minn)) || ((maksmaks > stok.biber) && (stok.biber >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s7 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.biber <= minmaks) || (stok.biber >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s7 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 8: " << s8 << " stokta " << stok.salatalik << " kilo var." << endl;
      if( ((minmaks < stok.salatalik) && (stok.salatalik <= minn)) || ((maksmaks > stok.salatalik) && (stok.salatalik >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s8 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.salatalik <= minmaks) || (stok.salatalik >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s8 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 9: " << s9 << " stokta " << stok.limon << " kilo var." << endl;
      if( ((minmaks < stok.limon) && (stok.limon <= minn)) || ((maksmaks > stok.limon) && (stok.limon >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s9 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.limon <= minmaks) || (stok.limon >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s9 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 10: " << s10 << " stokta " << stok.fasulye << " kilo var." << endl;
      if( ((minmaks < stok.fasulye) && (stok.fasulye <= minn)) || ((maksmaks > stok.fasulye) && (stok.fasulye >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s10 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.fasulye <= minmaks) || (stok.fasulye >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s10 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 11: " << s11 << " stokta " << stok.kabak << " kilo var." << endl;
      if( ((minmaks < stok.kabak) && (stok.kabak <= minn)) || ((maksmaks > stok.kabak) && (stok.kabak >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s11 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.kabak <= minmaks) || (stok.kabak >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s11 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 12: " << s12 << " stokta " << stok.sarimsak << " kilo var." << endl;
      if( ((minmaks < stok.sarimsak) && (stok.sarimsak <= minn)) || ((maksmaks > stok.sarimsak) && (stok.sarimsak >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s12 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.sarimsak <= minmaks) || (stok.sarimsak >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s12 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 13: " << s13 << " stokta " << stok.lahana << " kilo var." << endl;
      if( ((minmaks < stok.lahana) && (stok.lahana <= minn)) || ((maksmaks > stok.lahana) && (stok.lahana >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s13 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.lahana <= minmaks) || (stok.lahana >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s13 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 14: " << s14 << " stokta " << stok.pirasa << " kilo var." << endl;
      if( ((minmaks < stok.pirasa) && (stok.pirasa <= minn)) || ((maksmaks > stok.pirasa) && (stok.pirasa >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s14 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.pirasa <= minmaks) || (stok.pirasa >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s14 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 15: " << s15 << " stokta " << stok.brokoli << " kilo var." << endl;
      if( ((minmaks < stok.brokoli) && (stok.brokoli <= minn)) || ((maksmaks > stok.brokoli) && (stok.brokoli >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s15 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.brokoli <= minmaks) || (stok.brokoli >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s15 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 16: " << s16 << " stokta " << stok.muz << " kilo var." << endl;
      if( ((minmaks < stok.muz) && (stok.muz <= minn)) || ((maksmaks > stok.muz) && (stok.muz >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s16 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.muz <= minmaks) || (stok.muz >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s16 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 17: " << s17 << " stokta " << stok.silor << " kilo var." << endl;
      if( ((minmaks < stok.silor) && (stok.silor <= minn)) || ((maksmaks > stok.silor) && (stok.silor >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s17 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.silor <= minmaks) || (stok.silor >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s17 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 18: " << s18 << " stokta " << stok.turp << " kilo var." << endl;
      if( ((minmaks < stok.turp) && (stok.turp <= minn)) || ((maksmaks > stok.turp) && (stok.turp >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s18 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.turp <= minmaks) || (stok.turp >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s18 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 19: " << s19 << " stokta " << stok.ispanak << " kilo var." << endl;
      if( ((minmaks < stok.ispanak) && (stok.ispanak <= minn)) || ((maksmaks > stok.ispanak) && (stok.ispanak >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s19 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.ispanak <= minmaks) || (stok.ispanak >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s19 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 20: " << s20 << " stokta " << stok.kereviz << " kilo var." << endl;
      if( ((minmaks < stok.kereviz) && (stok.kereviz <= minn)) || ((maksmaks > stok.kereviz) && (stok.kereviz >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s20 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.kereviz <= minmaks) || (stok.kereviz >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s20 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 21: " << s21 << " stokta " << stok.karnabahar << " kilo var." << endl;
      if( ((minmaks < stok.karnabahar) && (stok.karnabahar <= minn)) || ((maksmaks > stok.karnabahar) && (stok.karnabahar >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s21 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.karnabahar <= minmaks) || (stok.karnabahar >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s21 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 22: " << s22 << " stokta " << stok.semizotu << " kilo var." << endl;
      if( ((minmaks < stok.semizotu) && (stok.semizotu <= minn)) || ((maksmaks > stok.semizotu) && (stok.semizotu >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s22 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.semizotu <= minmaks) || (stok.semizotu >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s22 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 23: " << s23 << " stokta " << stok.lahana << " kilo var." << endl;
      if( ((minmaks < stok.lahana) && (stok.lahana <= minn)) || ((maksmaks > stok.lahana) && (stok.lahana >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << s23 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.lahana <= minmaks) || (stok.lahana >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << s23 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 24: " << m1 << " stokta " << stok.portakal << " kilo var." << endl;
      if( ((minmaks < stok.portakal) && (stok.portakal <= minn)) || ((maksmaks > stok.portakal) && (stok.portakal >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << m1 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.portakal <= minmaks) || (stok.portakal >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << m1 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 25: " << m2 << " stokta " << stok.cilek << " kilo var." << endl;
      if( ((minmaks < stok.cilek) && (stok.cilek <= minn)) || ((maksmaks > stok.cilek) && (stok.cilek >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << m2 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.cilek <= minmaks) || (stok.cilek >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << m2 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 26: " << m3 << " stokta " << stok.erik << " kilo var." << endl;
      if( ((minmaks < stok.erik) && (stok.erik <= minn)) || ((maksmaks > stok.erik) && (stok.erik >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << m3 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.erik <= minmaks) || (stok.erik >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << m3 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 27: " << m4 << " stokta " << stok.elma << " kilo var." << endl;
      if( ((minmaks < stok.elma) && (stok.elma <= minn)) || ((maksmaks > stok.elma) && (stok.elma >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << m4 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.elma <= minmaks) || (stok.elma >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << m4 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 28: " << m5 << " stokta " << stok.karpuz << " kilo var." << endl;
      if( ((minmaks < stok.karpuz) && (stok.karpuz <= minn)) || ((maksmaks > stok.karpuz) && (stok.karpuz >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << m5 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.karpuz <= minmaks) || (stok.karpuz >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << m5 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }     
      cout << "                                     | 29: " << m6 << " stokta " << stok.kavun << " kilo var." << endl;
      if( ((minmaks < stok.kavun) && (stok.kavun <= minn)) || ((maksmaks > stok.kavun) && (stok.kavun >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << m6 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.kavun <= minmaks) || (stok.kavun >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << m6 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 30: " << m7 << " stokta " << stok.armut << " kilo var." << endl;
      if( ((minmaks < stok.armut) && (stok.armut <= minn)) || ((maksmaks > stok.armut) && (stok.armut >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << m7 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.armut <= minmaks) || (stok.armut >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << m7 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 31: " << m8 << " stokta " << stok.mandalina << " kilo var." << endl;
      if( ((minmaks < stok.mandalina) && (stok.mandalina <= minn)) || ((maksmaks > stok.mandalina) && (stok.mandalina >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << m8 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.mandalina <= minmaks) || (stok.mandalina >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << m8 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 32: " << m9 << " stokta " << stok.kivi << " kilo var." << endl;
      if( ((minmaks < stok.kivi) && (stok.kivi <= minn)) || ((maksmaks > stok.kivi) && (stok.kivi >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << m9 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.kivi <= minmaks) || (stok.kivi >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << m9 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 33: " << m10 << " stokta " << stok.uzum << " kilo var." << endl;
      if( ((minmaks < stok.uzum) && (stok.uzum <= minn)) || ((maksmaks > stok.uzum) && (stok.uzum >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << m10 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.uzum <= minmaks) || (stok.uzum >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << m10 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }     
      cout << "                                     | 34: " << m11 << " stokta " << stok.nektarin << " kilo var." << endl;
      if( ((minmaks < stok.nektarin) && (stok.nektarin <= minn)) || ((maksmaks > stok.nektarin) && (stok.nektarin >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << m11 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.nektarin <= minmaks) || (stok.nektarin >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << m11 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 35: " << m12 << " stokta " << stok.nar << " kilo var." << endl;
      if( ((minmaks < stok.nar) && (stok.nar <= minn)) || ((maksmaks > stok.nar) && (stok.nar >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << m12 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.nar <= minmaks) || (stok.nar >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << m12 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 36: " << m13 << " stokta " << stok.avakado << " kilo var." << endl;
      if( ((minmaks < stok.avakado) && (stok.avakado <= minn)) || ((maksmaks > stok.avakado) && (stok.avakado >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << m13 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.avakado <= minmaks) || (stok.avakado >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << m13 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 37: " << m14 << " stokta " << stok.seftali << " kilo var." << endl;
      if( ((minmaks < stok.seftali) && (stok.seftali <= minn)) || ((maksmaks > stok.seftali) && (stok.seftali >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << m14 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.seftali <= minmaks) || (stok.seftali >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << m14 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      cout << "                                     | 38: " << m15 << " stokta " << stok.greyfurt << " kilo var." << endl;
      if( ((minmaks < stok.greyfurt) && (stok.greyfurt <= minn)) || ((maksmaks > stok.greyfurt) && (stok.greyfurt >= maks)) )
      {
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      cout << "                                     | !: " << m15 << " stok limiti aþýldý!" << endl;
 
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }    
      
      if((stok.greyfurt <= minmaks) || (stok.greyfurt >= maksmaks))
      {
          SetConsoleTextAttribute(hConsole, 252);
      cout << "                                     | !!!: " << m15 << " stok limiti kritik düzeyde aþýldý!" << endl;
          Beep(1000,100);
          SetConsoleTextAttribute(hConsole, 15);
      }   
      cout << "                                     ***************************************************" << endl;
      
}

//Kazanç listesi

void kazancliste(urunler& kazanc)
{
 ifstream oku4("kazanclistesi.txt");
oku4 >> kazanc.mantar >> kazanc.patates >> kazanc.sogan >>  kazanc.domates >>  kazanc.patlican >> kazanc.havuc >> kazanc.biber >> kazanc.salatalik
>> kazanc.limon >> kazanc.fasulye >> kazanc.kabak >> kazanc.sarimsak >> kazanc.lahana >> kazanc.pirasa >> kazanc.brokoli >> kazanc.muz 
>> kazanc.silor >> kazanc.turp >> kazanc.ispanak >> kazanc.kereviz >> kazanc.karnabahar >> kazanc.semizotu >> kazanc.lahana >> kazanc.kabak >> kazanc.portakal 
>> kazanc.cilek >> kazanc.erik >> kazanc.elma >> kazanc.karpuz >> kazanc.kavun >> kazanc.armut >> kazanc.mandalina >> kazanc.kivi >> kazanc.uzum 
>> kazanc.nektarin >> kazanc.nar >> kazanc.avakado >> kazanc.seftali >> kazanc.greyfurt;

      cout << "                                     ***************************************************" << endl;
      cout << "                                     | 1: " << s1 << " ile elde edilen kazanç = " << kazanc.mantar << " TL" << endl;
      cout << "                                     | 2: " << s2 << " ile elde edilen kazanç = " << kazanc.patates << " TL" << endl;
      cout << "                                     | 3: " << s3 << " ile elde edilen kazanç = " << kazanc.sogan << " TL" << endl;
      cout << "                                     | 4: " << s4 << " ile elde edilen kazanç = " << kazanc.domates << " TL" << endl;
      cout << "                                     | 5: " << s5 << " ile elde edilen kazanç = " << kazanc.patlican << " TL" << endl;
      cout << "                                     | 6: " << s6 << " ile elde edilen kazanç = " << kazanc.havuc << " TL" << endl;
      cout << "                                     | 7: " << s7 << " ile elde edilen kazanç = " << kazanc.biber << " TL" << endl;
      cout << "                                     | 8: " << s8 << " ile elde edilen kazanç = " << kazanc.salatalik << " TL" << endl;
      cout << "                                     | 9: " << s9 << " ile elde edilen kazanç = " << kazanc.limon << " TL" << endl;
      cout << "                                     | 10: " << s10 << " ile elde edilen kazanç = " << kazanc.fasulye << " TL" << endl;
      cout << "                                     | 11: " << s11 << " ile elde edilen kazanç = " << kazanc.kabak << " TL" << endl;
      cout << "                                     | 12: " << s12 << " ile elde edilen kazanç = " << kazanc.sarimsak << " TL" << endl;
      cout << "                                     | 13: " << s13 << " ile elde edilen kazanç = " << kazanc.lahana << " TL" << endl;
      cout << "                                     | 14: " << s14 << " ile elde edilen kazanç = " << kazanc.pirasa << " TL" << endl;
      cout << "                                     | 15: " << s15 << " ile elde edilen kazanç = " << kazanc.brokoli << " TL" << endl;
      cout << "                                     | 16: " << s16 << " ile elde edilen kazanç = " << kazanc.muz << " TL" << endl;
      cout << "                                     | 17: " << s17 << " ile elde edilen kazanç = " << kazanc.silor << " TL" << endl;
      cout << "                                     | 18: " << s18 << " ile elde edilen kazanç = " << kazanc.turp << " TL" << endl;
      cout << "                                     | 19: " << s19 << " ile elde edilen kazanç = " << kazanc.ispanak << " TL" << endl;
      cout << "                                     | 20: " << s20 << " ile elde edilen kazanç = " << kazanc.kereviz << " TL" << endl;
      cout << "                                     | 21: " << s21 << " ile elde edilen kazanç = " << kazanc.karnabahar << " TL" << endl;
      cout << "                                     | 22: " << s22 << " ile elde edilen kazanç = " << kazanc.semizotu << " TL" << endl;
      cout << "                                     | 23: " << s23 << " ile elde edilen kazanç = " << kazanc.lahana << " TL" << endl;
      cout << "                                     | 24: " << m1 << " ile elde edilen kazanç = " << kazanc.portakal << " TL" << endl;
      cout << "                                     | 25: " << m2 << " ile elde edilen kazanç = " << kazanc.cilek << " TL" << endl;
      cout << "                                     | 26: " << m3 << " ile elde edilen kazanç = " << kazanc.erik << " TL" << endl;
      cout << "                                     | 27: " << m4 << " ile elde edilen kazanç = " << kazanc.elma << " TL" << endl;
      cout << "                                     | 28: " << m5 << " ile elde edilen kazanç = " << kazanc.karpuz << " TL" << endl; 
      cout << "                                     | 29: " << m6 << " ile elde edilen kazanç = " << kazanc.kavun << " TL" << endl;
      cout << "                                     | 30: " << m7 << " ile elde edilen kazanç = " << kazanc.armut << " TL" << endl;
      cout << "                                     | 31: " << m8 << " ile elde edilen kazanç = " << kazanc.mandalina << " TL" << endl;
      cout << "                                     | 32: " << m9 << " ile elde edilen kazanç = " << kazanc.kivi << " TL" << endl;
      cout << "                                     | 33: " << m10 << " ile elde edilen kazanç = " << kazanc.uzum << " TL" << endl; 
      cout << "                                     | 34: " << m11 << " ile elde edilen kazanç = " << kazanc.nektarin << " TL" << endl;
      cout << "                                     | 35: " << m12 << " ile elde edilen kazanç = " << kazanc.nar << " TL" << endl;
      cout << "                                     | 36: " << m13 << " ile elde edilen kazanç = " << kazanc.avakado << " TL" << endl;
      cout << "                                     | 37: " << m14 << " ile elde edilen kazanç = " << kazanc.seftali << " TL" << endl;
      cout << "                                     | 38: " << m15 << " ile elde edilen kazanç = " << kazanc.greyfurt << " TL" << endl;
      cout << "                                     *****************************************************" << endl;

}

//Satýþ listesini manuel güncelleme

float guncelle(urunler& fiyat)
{
ifstream oku("fiyatlistesi.txt");
oku >> fiyat.mantar >> fiyat.patates >> fiyat.sogan >>  fiyat.domates >>  fiyat.patlican >> fiyat.havuc >> fiyat.biber >> fiyat.salatalik
>> fiyat.limon >> fiyat.fasulye >> fiyat.kabak >> fiyat.sarimsak >> fiyat.lahana >> fiyat.pirasa >> fiyat.brokoli >> fiyat.muz 
>> fiyat.silor >> fiyat.turp >> fiyat.ispanak >> fiyat.kereviz >> fiyat.karnabahar >> fiyat.semizotu >> fiyat.lahana >> fiyat.kabak >> fiyat.portakal 
>> fiyat.cilek >> fiyat.erik >> fiyat.elma >> fiyat.karpuz >> fiyat.kavun >> fiyat.armut >> fiyat.mandalina >> fiyat.kivi >> fiyat.uzum 
>> fiyat.nektarin >> fiyat.nar >> fiyat.avakado >> fiyat.seftali >> fiyat.greyfurt;

  while((tekrar != 'H') && (tekrar != 'h'))
  {
      cout << "-----------------------------------------------------------------" << endl;
      cout << "| 1: " << s1 << " kilosu " << fiyat.mantar << " TL" << endl;
      cout << "| 2: " << s2 << " kilosu " << fiyat.patates << " TL" << endl;
      cout << "| 3: " << s3 << " kilosu " << fiyat.sogan << " TL" << endl;
      cout << "| 4: " << s4 << " kilosu " << fiyat.domates << " TL" << endl;
      cout << "| 5: " << s5 << " kilosu " << fiyat.patlican << " TL" << endl;
      cout << "| 6: " << s6 << " kilosu " << fiyat.havuc << " TL" << endl;
      cout << "| 7: " << s7 << " kilosu " << fiyat.biber << " TL" << endl;
      cout << "| 8: " << s8 << " kilosu " << fiyat.salatalik << " TL" << endl;
      cout << "| 9: " << s9 << " kilosu " << fiyat.limon << " TL" << endl;
      cout << "| 10: " << s10 << " kilosu " << fiyat.fasulye << " TL" << endl;
      cout << "| 11: " << s11 << " kilosu " << fiyat.kabak << " TL" << endl;
      cout << "| 12: " << s12 << " kilosu " << fiyat.sarimsak << " TL" << endl;
      cout << "| 13: " << s13 << " kilosu " << fiyat.lahana << " TL" << endl;
      cout << "| 14: " << s14 << " kilosu " << fiyat.pirasa << " TL" << endl;
      cout << "| 15: " << s15 << " kilosu " << fiyat.brokoli << " TL" << endl;
      cout << "| 16: " << s16 << " kilosu " << fiyat.muz << " TL" << endl;
      cout << "| 17: " << s17 << " kilosu " << fiyat.silor << " TL" << endl;
      cout << "| 18: " << s18 << " kilosu " << fiyat.turp << " TL" << endl;
      cout << "| 19: " << s19 << " kilosu " << fiyat.ispanak << " TL" << endl;
      cout << "| 20: " << s20 << " kilosu " << fiyat.kereviz << " TL" << endl;
      cout << "| 21: " << s21 << " kilosu " << fiyat.karnabahar << " TL" << endl;
      cout << "| 22: " << s22 << " kilosu " << fiyat.semizotu << " TL" << endl;
      cout << "| 23: " << s23 << " kilosu " << fiyat.lahana << " TL" << endl;
      cout << "| 24: " << m1 << " kilosu " << fiyat.portakal << " TL" << endl;
      cout << "| 25: " << m2 << " kilosu " << fiyat.cilek << " TL" << endl;
      cout << "| 26: " << m3 << " kilosu " << fiyat.erik << " TL" << endl;
      cout << "| 27: " << m4 << " kilosu " << fiyat.elma << " TL" << endl;
      cout << "| 28: " << m5 << " kilosu " << fiyat.karpuz << " TL" << endl; 
      cout << "| 29: " << m6 << " kilosu " << fiyat.kavun << " TL" << endl;
      cout << "| 30: " << m7 << " kilosu " << fiyat.armut << " TL" << endl;
      cout << "| 31: " << m8 << " kilosu " << fiyat.mandalina << " TL" << endl;
      cout << "| 32: " << m9 << " kilosu " << fiyat.kivi << " TL" << endl;
      cout << "| 33: " << m10 << " kilosu " << fiyat.uzum << " TL" << endl; 
      cout << "| 34: " << m11 << " kilosu " << fiyat.nektarin << " TL" << endl;
      cout << "| 35: " << m12 << " kilosu " << fiyat.nar << " TL" << endl;
      cout << "| 36: " << m13 << " kilosu " << fiyat.avakado << " TL" << endl;
      cout << "| 37: " << m14 << " kilosu " << fiyat.seftali << " TL" << endl;
      cout << "| 38: " << m15 << " kilosu " << fiyat.greyfurt << " TL" << endl;
      cout << "| 0:   Vazgeç " << endl; 
      cout << "-----------------------------------------------------------------" << endl;
      cout << "|Güncellemek istediðiniz ürünün numarasýný giriniz." << endl;
      cout << "| ";
      cin >> secim2;
      cout << "-----------------------------------------------------------------" << endl;
  switch(secim2)
  {
  case 1: 
   {
    cout << "Yeni " << s1 << " fiyatýný giriniz." << endl;
    cin >> fiyat.mantar; 
    break;       
   }    
  case 2: 
   {
    cout << "Yeni " << s2 << " fiyatýný giriniz." << endl;
    cin >> fiyat.patates; 
    break;       
   }
  case 3: 
   {
    cout << "Yeni " << s3 << " fiyatýný giriniz." << endl;
    cin >> fiyat.sogan; 
    break;       
   }
  case 4: 
   {
    cout << "Yeni " << s4 << " fiyatýný giriniz." << endl;
    cin >> fiyat.domates; 
    break;       
   }
  case 5: 
   {
    cout << "Yeni " << s5 << " fiyatýný giriniz." << endl;
    cin >> fiyat.patlican; 
    break;       
   }
  case 6: 
   {
    cout << "Yeni " << s6 << " fiyatýný giriniz." << endl;
    cin >> fiyat.havuc; 
    break;       
   }
  case 7: 
   {
    cout << "Yeni " << s7 << " fiyatýný giriniz." << endl;
    cin >> fiyat.biber; 
    break;       
   }
  case 8: 
   {
    cout << "Yeni " << s8 << " fiyatýný giriniz." << endl;
    cin >> fiyat.salatalik; 
    break;       
   }
  case 9: 
   {
    cout << "Yeni " << s9 << " fiyatýný giriniz." << endl;
    cin >> fiyat.limon; 
    break;       
   }
  case 10: 
   {
    cout << "Yeni " << s10 << " fiyatýný giriniz." << endl;
    cin >> fiyat.fasulye; 
    break;       
   }
  case 11: 
   {
    cout << "Yeni " << s11 << " fiyatýný giriniz." << endl;
    cin >> fiyat.kabak; 
    break;       
   }
  case 12: 
   {
    cout << "Yeni " << s12 << " fiyatýný giriniz." << endl;
    cin >> fiyat.sarimsak; 
    break;       
   }
  case 13: 
   {
    cout << "Yeni " << s13 << " fiyatýný giriniz." << endl;
    cin >> fiyat.lahana; 
    break;       
   } 
  case 14: 
   {
    cout << "Yeni " << s14 << " fiyatýný giriniz." << endl;
    cin >> fiyat.pirasa; 
    break;       
   }    
  case 15: 
   {
    cout << "Yeni " << s15 << " fiyatýný giriniz." << endl;
    cin >> fiyat.brokoli; 
    break;       
   }
  case 16: 
   {
    cout << "Yeni " << s16 << " fiyatýný giriniz." << endl;
    cin >> fiyat.muz; 
    break;       
   }
  case 17: 
   {
    cout << "Yeni " << s17 << " fiyatýný giriniz." << endl;
    cin >> fiyat.silor; 
    break;       
   }
  case 18: 
   {
    cout << "Yeni " << s18 << " fiyatýný giriniz." << endl;
    cin >> fiyat.turp; 
    break;       
   }
  case 19: 
   {
    cout << "Yeni " << s19 << " fiyatýný giriniz." << endl;
    cin >> fiyat.ispanak; 
    break;       
   }
  case 20: 
   {
    cout << "Yeni " << s20 << " fiyatýný giriniz." << endl;
    cin >> fiyat.kereviz; 
    break;       
   }
  case 21: 
   {
    cout << "Yeni " << s21 << " fiyatýný giriniz." << endl;
    cin >> fiyat.karnabahar; 
    break;       
   }
  case 22: 
   {
    cout << "Yeni " << s22 << " fiyatýný giriniz." << endl;
    cin >> fiyat.semizotu; 
    break;       
   }
  case 23: 
   {
    cout << "Yeni " << s23 << " fiyatýný giriniz." << endl;
    cin >> fiyat.lahana; 
    break;       
   }
  case 24: 
   {
    cout << "Yeni " << m1 << " fiyatýný giriniz." << endl;
    cin >> fiyat.portakal; 
    break;       
   }
  case 25: 
   {
    cout << "Yeni " << m2 << " fiyatýný giriniz." << endl;
    cin >> fiyat.cilek; 
    break;       
   } 
  case 26: 
   {
    cout << "Yeni " << m3 << " fiyatýný giriniz." << endl;
    cin >> fiyat.erik; 
    break;       
   }    
  case 27: 
   {
    cout << "Yeni " << m4 << " fiyatýný giriniz." << endl;
    cin >> fiyat.elma; 
    break;       
   }
  case 28: 
   {
    cout << "Yeni " << m5 << " fiyatýný giriniz." << endl;
    cin >> fiyat.karpuz; 
    break;       
   }
  case 29: 
   {
    cout << "Yeni " << m6 << " fiyatýný giriniz." << endl;
    cin >> fiyat.kavun; 
    break;       
   }
  case 30: 
   {
    cout << "Yeni " << m7 << " fiyatýný giriniz." << endl;
    cin >> fiyat.armut; 
    break;       
   }
  case 31: 
   {
    cout << "Yeni " << m8 << " fiyatýný giriniz." << endl;
    cin >> fiyat.mandalina; 
    break;       
   }
  case 32: 
   {
    cout << "Yeni " << m9 << " fiyatýný giriniz." << endl;
    cin >> fiyat.kivi; 
    break;       
   }
  case 33: 
   {
    cout << "Yeni " << m10 << " fiyatýný giriniz." << endl;
    cin >> fiyat.uzum; 
    break;       
   }
  case 34: 
   {
    cout << "Yeni " << m11 << " fiyatýný giriniz." << endl;
    cin >> fiyat.nektarin; 
    break;       
   }
  case 35: 
   {
    cout << "Yeni " << m12 << " fiyatýný giriniz." << endl;
    cin >> fiyat.nar; 
    break;       
   }
  case 36: 
   {
    cout << "Yeni " << m13 << " fiyatýný giriniz." << endl;
    cin >> fiyat.avakado; 
    break;       
   }
  case 37: 
   {
    cout << "Yeni " << m14 << " fiyatýný giriniz." << endl;
    cin >> fiyat.seftali; 
    break;       
   }
  case 38: 
   {
    cout << "Yeni " << m15 << " fiyatýný giriniz." << endl;
    cin >> fiyat.greyfurt; 
    break;       
   } 
  }
  cout << "*****************************************************************" << endl;
  cout << "| Daha fazla secmek istermisiniz?[E/H]" << endl;
  cin.ignore();
  cin >> tekrar;
  } 
  ofstream yaz("fiyatlistesi.txt");
 yaz << fiyat.mantar << " " << fiyat.patates << " " << fiyat.sogan << " " << fiyat.domates << " " << fiyat.patlican << " " << fiyat.havuc << " " << fiyat.biber << " " << fiyat.salatalik << " "
 << fiyat.limon << " " << fiyat.fasulye << " " << fiyat.kabak << " " << fiyat.sarimsak << " " << fiyat.lahana << " " << fiyat.pirasa << " " << fiyat.brokoli << " " << fiyat.muz << " "
 << fiyat.silor << " " << fiyat.turp <<  " " << fiyat.ispanak << " " << fiyat.kereviz << " " << fiyat.karnabahar << " " << fiyat.semizotu << " " << fiyat.lahana << " " << fiyat.kabak << " " << fiyat.portakal << " "
 << fiyat.cilek << " " << fiyat.erik << " " << fiyat.elma << " " << fiyat.karpuz << " " << fiyat.kavun << " " << fiyat.armut << " " << fiyat.mandalina << " " << fiyat.kivi << " " << fiyat.uzum << " "
 << fiyat.nektarin << " " << fiyat.nar << " " << fiyat.avakado << " " << fiyat.seftali << " " << fiyat.greyfurt << " ";
}

//Alýþ listesini manuel güncelleme

float guncelle2(urunler& alis)
{
ifstream oku2("alislistesi.txt");
oku2 >> alis.mantar >> alis.patates >> alis.sogan >>  alis.domates >>  alis.patlican >> alis.havuc >> alis.biber >> alis.salatalik
>> alis.limon >> alis.fasulye >> alis.kabak >> alis.sarimsak >> alis.lahana >> alis.pirasa >> alis.brokoli >> alis.muz 
>> alis.silor >> alis.turp >> alis.ispanak >> alis.kereviz >> alis.karnabahar >> alis.semizotu >> alis.lahana >> alis.kabak >> alis.portakal 
>> alis.cilek >> alis.erik >> alis.elma >> alis.karpuz >> alis.kavun >> alis.armut >> alis.mandalina >> alis.kivi >> alis.uzum 
>> alis.nektarin >> alis.nar >> alis.avakado >> alis.seftali >> alis.greyfurt;


  while((tekrar != 'H') && (tekrar != 'h'))
  {
      cout << "-----------------------------------------------------------------" << endl;
      cout << "| 1: " << s1 << " kilosu " << alis.mantar << " TL" << endl;
      cout << "| 2: " << s2 << " kilosu " << alis.patates << " TL" << endl;
      cout << "| 3: " << s3 << " kilosu " << alis.sogan << " TL" << endl;
      cout << "| 4: " << s4 << " kilosu " << alis.domates << " TL" << endl;
      cout << "| 5: " << s5 << " kilosu " << alis.patlican << " TL" << endl;
      cout << "| 6: " << s6 << " kilosu " << alis.havuc << " TL" << endl;
      cout << "| 7: " << s7 << " kilosu " << alis.biber << " TL" << endl;
      cout << "| 8: " << s8 << " kilosu " << alis.salatalik << " TL" << endl;
      cout << "| 9: " << s9 << " kilosu " << alis.limon << " TL" << endl;
      cout << "| 10: " << s10 << " kilosu " << alis.fasulye << " TL" << endl;
      cout << "| 11: " << s11 << " kilosu " << alis.kabak << " TL" << endl;
      cout << "| 12: " << s12 << " kilosu " << alis.sarimsak << " TL" << endl;
      cout << "| 13: " << s13 << " kilosu " << alis.lahana << " TL" << endl;
      cout << "| 14: " << s14 << " kilosu " << alis.pirasa << " TL" << endl;
      cout << "| 15: " << s15 << " kilosu " << alis.brokoli << " TL" << endl;
      cout << "| 16: " << s16 << " kilosu " << alis.muz << " TL" << endl;
      cout << "| 17: " << s17 << " kilosu " << alis.silor << " TL" << endl;
      cout << "| 18: " << s18 << " kilosu " << alis.turp << " TL" << endl;
      cout << "| 19: " << s19 << " kilosu " << alis.ispanak << " TL" << endl;
      cout << "| 20: " << s20 << " kilosu " << alis.kereviz << " TL" << endl;
      cout << "| 21: " << s21 << " kilosu " << alis.karnabahar << " TL" << endl;
      cout << "| 22: " << s22 << " kilosu " << alis.semizotu << " TL" << endl;
      cout << "| 23: " << s23 << " kilosu " << alis.lahana << " TL" << endl;
      cout << "| 24: " << m1 << " kilosu " << alis.portakal << " TL" << endl;
      cout << "| 25: " << m2 << " kilosu " << alis.cilek << " TL" << endl;
      cout << "| 26: " << m3 << " kilosu " << alis.erik << " TL" << endl;
      cout << "| 27: " << m4 << " kilosu " << alis.elma << " TL" << endl;
      cout << "| 28: " << m5 << " kilosu " << alis.karpuz << " TL" << endl; 
      cout << "| 29: " << m6 << " kilosu " << alis.kavun << " TL" << endl;
      cout << "| 30: " << m7 << " kilosu " << alis.armut << " TL" << endl;
      cout << "| 31: " << m8 << " kilosu " << alis.mandalina << " TL" << endl;
      cout << "| 32: " << m9 << " kilosu " << alis.kivi << " TL" << endl;
      cout << "| 33: " << m10 << " kilosu " << alis.uzum << " TL" << endl; 
      cout << "| 34: " << m11 << " kilosu " << alis.nektarin << " TL" << endl;
      cout << "| 35: " << m12 << " kilosu " << alis.nar << " TL" << endl;
      cout << "| 36: " << m13 << " kilosu " << alis.avakado << " TL" << endl;
      cout << "| 37: " << m14 << " kilosu " << alis.seftali << " TL" << endl;
      cout << "| 38: " << m15 << " kilosu " << alis.greyfurt << " TL" << endl;
      cout << "| 0:   Vazgeç " << endl;
      cout << "-----------------------------------------------------------------" << endl; 
      cout << "|Güncellemek istediðiniz ürünün numarasýný giriniz." << endl;
      cout << "| ";
      cin >> secim2;
      cout << "-----------------------------------------------------------------" << endl;
  switch(secim2)
  {
  case 1: 
   {
    cout << "Yeni " << s1 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.mantar; 
    break;       
   }    
  case 2: 
   {
    cout << "Yeni " << s2 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.patates; 
    break;       
   }
  case 3: 
   {
    cout << "Yeni " << s3 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.sogan; 
    break;       
   }
  case 4: 
   {
    cout << "Yeni " << s4 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.domates; 
    break;       
   }
  case 5: 
   {
    cout << "Yeni " << s5 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.patlican; 
    break;       
   }
  case 6: 
   {
    cout << "Yeni " << s6 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.havuc; 
    break;       
   }
  case 7: 
   {
    cout << "Yeni " << s7 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.biber; 
    break;       
   }
  case 8: 
   {
    cout << "Yeni " << s8 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.salatalik; 
    break;       
   }
  case 9: 
   {
    cout << "Yeni " << s9 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.limon; 
    break;       
   }
  case 10: 
   {
    cout << "Yeni " << s10 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.fasulye; 
    break;       
   }
  case 11: 
   {
    cout << "Yeni " << s11 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.kabak; 
    break;       
   }
  case 12: 
   {
    cout << "Yeni " << s12 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.sarimsak; 
    break;       
   }
  case 13: 
   {
    cout << "Yeni " << s13 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.lahana; 
    break;       
   } 
  case 14: 
   {
    cout << "Yeni " << s14 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.pirasa; 
    break;       
   }    
  case 15: 
   {
    cout << "Yeni " << s15 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.brokoli; 
    break;       
   }
  case 16: 
   {
    cout << "Yeni " << s16 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.muz; 
    break;       
   }
  case 17: 
   {
    cout << "Yeni " << s17 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.silor; 
    break;       
   }
  case 18: 
   {
    cout << "Yeni " << s18 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.turp; 
    break;       
   }
  case 19: 
   {
    cout << "Yeni " << s19 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.ispanak; 
    break;       
   }
  case 20: 
   {
    cout << "Yeni " << s20 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.kereviz; 
    break;       
   }
  case 21: 
   {
    cout << "Yeni " << s21 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.karnabahar; 
    break;       
   }
  case 22: 
   {
    cout << "Yeni " << s22 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.semizotu; 
    break;       
   }
  case 23: 
   {
    cout << "Yeni " << s23 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.lahana; 
    break;       
   }
  case 24: 
   {
    cout << "Yeni " << m1 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.portakal; 
    break;       
   }
  case 25: 
   {
    cout << "Yeni " << m2 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.cilek; 
    break;       
   } 
  case 26: 
   {
    cout << "Yeni " << m3 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.erik; 
    break;       
   }    
  case 27: 
   {
    cout << "Yeni " << m4 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.elma; 
    break;       
   }
  case 28: 
   {
    cout << "Yeni " << m5 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.karpuz; 
    break;       
   }
  case 29: 
   {
    cout << "Yeni " << m6 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.kavun; 
    break;       
   }
  case 30: 
   {
    cout << "Yeni " << m7 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.armut; 
    break;       
   }
  case 31: 
   {
    cout << "Yeni " << m8 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.mandalina; 
    break;       
   }
  case 32: 
   {
    cout << "Yeni " << m9 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.kivi; 
    break;       
   }
  case 33: 
   {
    cout << "Yeni " << m10 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.uzum; 
    break;       
   }
  case 34: 
   {
    cout << "Yeni " << m11 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.nektarin; 
    break;       
   }
  case 35: 
   {
    cout << "Yeni " << m12 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.nar; 
    break;       
   }
  case 36: 
   {
    cout << "Yeni " << m13 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.avakado; 
    break;       
   }
  case 37: 
   {
    cout << "Yeni " << m14 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.seftali; 
    break;       
   }
  case 38: 
   {
    cout << "Yeni " << m15 << " alýþ fýyatýný giriniz." << endl;
    cin >> alis.greyfurt; 
    break;       
   } 
  }
  cout << "*****************************************************************" << endl;
  cout << "| Daha fazla secmek istermisiniz?[E/H]" << endl;
  cin.ignore();
  cin >> tekrar;
  } 
  ofstream yaz2("alislistesi.txt");
 yaz2 << alis.mantar << " " << alis.patates << " " << alis.sogan << " " << alis.domates << " " << alis.patlican << " " << alis.havuc << " " << alis.biber << " " << alis.salatalik << " "
 << alis.limon << " " << alis.fasulye << " " << alis.kabak << " " << alis.sarimsak << " " << alis.lahana << " " << alis.pirasa << " " << alis.brokoli << " " << alis.muz << " "
 << alis.silor << " " << alis.turp <<  " " << alis.ispanak << " " << alis.kereviz << " " << alis.karnabahar << " " << alis.semizotu << " " << alis.lahana << " " << alis.kabak << " " << alis.portakal << " "
 << alis.cilek << " " << alis.erik << " " << alis.elma << " " << alis.karpuz << " " << alis.kavun << " " << alis.armut << " " << alis.mandalina << " " << alis.kivi << " " << alis.uzum << " "
 << alis.nektarin << " " << alis.nar << " " << alis.avakado << " " << alis.seftali << " " << alis.greyfurt << " ";
}

//Stok listesini manuel güncelleme

float depo(urunler& stok)
{
  ifstream oku3("stoklistesi.txt");
oku3 >> stok.mantar >> stok.patates >> stok.sogan >>  stok.domates >>  stok.patlican >> stok.havuc >> stok.biber >> stok.salatalik
>> stok.limon >> stok.fasulye >> stok.kabak >> stok.sarimsak >> stok.lahana >> stok.pirasa >> stok.brokoli >> stok.muz 
>> stok.silor >> stok.turp >> stok.ispanak >> stok.kereviz >> stok.karnabahar >> stok.semizotu >> stok.lahana >> stok.kabak >> stok.portakal 
>> stok.cilek >> stok.erik >> stok.elma >> stok.karpuz >> stok.kavun >> stok.armut >> stok.mandalina >> stok.kivi >> stok.uzum 
>> stok.nektarin >> stok.nar >> stok.avakado >> stok.seftali >> stok.greyfurt;


  while((tekrar != 'H') && (tekrar != 'h'))
  {
      cout << "-----------------------------------------------------------------" << endl;
      cout << "| 1: " << s1 << " stokta " << stok.mantar << " kilo var." << endl;
      cout << "| 2: " << s2 << " stokta " << stok.patates << " kilo var." << endl;
      cout << "| 3: " << s3 << " stokta " << stok.sogan << " kilo var." << endl;
      cout << "| 4: " << s4 << " stokta " << stok.domates << "kilo var." << endl;
      cout << "| 5: " << s5 << " stokta " << stok.patlican << " kilo var." << endl;
      cout << "| 6: " << s6 << " stokta " << stok.havuc << " kilo var." << endl;
      cout << "| 7: " << s7 << " stokta " << stok.biber << " kilo var." << endl;
      cout << "| 8: " << s8 << " stokta " << stok.salatalik << " kilo var." << endl;
      cout << "| 9: " << s9 << " stokta " << stok.limon << " kilo var." << endl;
      cout << "| 10: " << s10 << " stokta " << stok.fasulye << " kilo var." << endl;
      cout << "| 11: " << s11 << " stokta " << stok.kabak << " kilo var." << endl;
      cout << "| 12: " << s12 << " stokta " << stok.sarimsak << " kilo var." << endl;
      cout << "| 13: " << s13 << " stokta " << stok.lahana << " kilo var." << endl;
      cout << "| 14: " << s14 << " stokta " << stok.pirasa << " kilo var." << endl;
      cout << "| 15: " << s15 << " stokta " << stok.brokoli << " kilo var." << endl;
      cout << "| 16: " << s16 << " stokta " << stok.muz << " kilo var." << endl;
      cout << "| 17: " << s17 << " stokta " << stok.silor << " kilo var." << endl;
      cout << "| 18: " << s18 << " stokta " << stok.turp << " kilo var." << endl;
      cout << "| 19: " << s19 << " stokta " << stok.ispanak << " kilo var." << endl;
      cout << "| 20: " << s20 << " stokta " << stok.kereviz << " kilo var." << endl;
      cout << "| 21: " << s21 << " stokta " << stok.karnabahar << " kilo var." << endl;
      cout << "| 22: " << s22 << " stokta " << stok.semizotu << " kilo var." << endl;
      cout << "| 23: " << s23 << " stokta " << stok.lahana << " kilo var." << endl;
      cout << "| 24: " << m1 << " stokta " << stok.portakal << " kilo var." << endl;
      cout << "| 25: " << m2 << " stokta " << stok.cilek << " kilo var." << endl;
      cout << "| 26: " << m3 << " stokta " << stok.erik << " kilo var." << endl;
      cout << "| 27: " << m4 << " stokta " << stok.elma << " kilo var." << endl;
      cout << "| 28: " << m5 << " stokta " << stok.karpuz << " kilo var." << endl; 
      cout << "| 29: " << m6 << " stokta " << stok.kavun << " kilo var." << endl;
      cout << "| 30: " << m7 << " stokta " << stok.armut << " kilo var." << endl;
      cout << "| 31: " << m8 << " stokta " << stok.mandalina << " kilo var." << endl;
      cout << "| 32: " << m9 << " stokta " << stok.kivi << " kilo var." << endl;
      cout << "| 33: " << m10 << " stokta " << stok.uzum << " kilo var." << endl; 
      cout << "| 34: " << m11 << " stokta " << stok.nektarin << " kilo var." << endl;
      cout << "| 35: " << m12 << " stokta " << stok.nar << " kilo var." << endl;
      cout << "| 36: " << m13 << " stokta " << stok.avakado << " kilo var." << endl;
      cout << "| 37: " << m14 << " stokta " << stok.seftali << " kilo var." << endl;
      cout << "| 38: " << m15 << " stokta " << stok.greyfurt << " kilo var." << endl;
      cout << "| 0:   Vazgeç " << endl; 
      cout << "-----------------------------------------------------------------" << endl; 
      cout << "|Güncellemek istediðiniz ürünün numarasýný giriniz." << endl;
      cout << "| ";
      cin >> secim2;
      cout << "-----------------------------------------------------------------" << endl;
  switch(secim2)
  {
  case 1: 
   {
    cout << "Yeni " << s1 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.mantar; 
    break;       
   }    
  case 2: 
   {
    cout << "Yeni " << s2 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.patates; 
    break;       
   }
  case 3: 
   {
    cout << "Yeni " << s3 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.sogan; 
    break;       
   }
  case 4: 
   {
    cout << "Yeni " << s4 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.domates; 
    break;       
   }
  case 5: 
   {
    cout << "Yeni " << s5 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.patlican; 
    break;       
   }
  case 6: 
   {
    cout << "Yeni " << s6 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.havuc; 
    break;       
   }
  case 7: 
   {
    cout << "Yeni " << s7 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.biber; 
    break;       
   }
  case 8: 
   {
    cout << "Yeni " << s8 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.salatalik; 
    break;       
   }
  case 9: 
   {
    cout << "Yeni " << s9 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.limon; 
    break;       
   }
  case 10: 
   {
    cout << "Yeni " << s10 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.fasulye; 
    break;       
   }
  case 11: 
   {
    cout << "Yeni " << s11 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.kabak; 
    break;       
   }
  case 12: 
   {
    cout << "Yeni " << s12 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.sarimsak; 
    break;       
   }
  case 13: 
   {
    cout << "Yeni " << s13 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.lahana; 
    break;       
   } 
  case 14: 
   {
    cout << "Yeni " << s14 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.pirasa; 
    break;       
   }    
  case 15: 
   {
    cout << "Yeni " << s15 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.brokoli; 
    break;       
   }
  case 16: 
   {
    cout << "Yeni " << s16 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.muz; 
    break;       
   }
  case 17: 
   {
    cout << "Yeni " << s17 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.silor; 
    break;       
   }
  case 18: 
   {
    cout << "Yeni " << s18 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.turp; 
    break;       
   }
  case 19: 
   {
    cout << "Yeni " << s19 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.ispanak; 
    break;       
   }
  case 20: 
   {
    cout << "Yeni " << s20 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.kereviz; 
    break;       
   }
  case 21: 
   {
    cout << "Yeni " << s21 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.karnabahar; 
    break;       
   }
  case 22: 
   {
    cout << "Yeni " << s22 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.semizotu; 
    break;       
   }
  case 23: 
   {
    cout << "Yeni " << s23 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.lahana; 
    break;       
   }
  case 24: 
   {
    cout << "Yeni " << m1 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.portakal; 
    break;       
   }
  case 25: 
   {
    cout << "Yeni " << m2 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.cilek; 
    break;       
   } 
  case 26: 
   {
    cout << "Yeni " << m3 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.erik; 
    break;       
   }    
  case 27: 
   {
    cout << "Yeni " << m4 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.elma; 
    break;       
   }
  case 28: 
   {
    cout << "Yeni " << m5 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.karpuz; 
    break;       
   }
  case 29: 
   {
    cout << "Yeni " << m6 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.kavun; 
    break;       
   }
  case 30: 
   {
    cout << "Yeni " << m7 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.armut; 
    break;       
   }
  case 31: 
   {
    cout << "Yeni " << m8 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.mandalina; 
    break;       
   }
  case 32: 
   {
    cout << "Yeni " << m9 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.kivi; 
    break;       
   }
  case 33: 
   {
    cout << "Yeni " << m10 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.uzum; 
    break;       
   }
  case 34: 
   {
    cout << "Yeni " << m11 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.nektarin; 
    break;       
   }
  case 35: 
   {
    cout << "Yeni " << m12 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.nar; 
    break;       
   }
  case 36: 
   {
    cout << "Yeni " << m13 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.avakado; 
    break;       
   }
  case 37: 
   {
    cout << "Yeni " << m14 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.seftali; 
    break;       
   }
  case 38: 
   {
    cout << "Yeni " << m15 << " stoktaki miktari giriniz. " << endl;
    cin >> stok.greyfurt; 
    break;       
   } 
  }
  cout << "*****************************************************************" << endl;
  cout << "| Daha fazla secmek istermisiniz?[E/H]" << endl;
  cin.ignore();
  cin >> tekrar;
  } 
  ofstream yaz3("stoklistesi.txt");
 yaz3 << stok.mantar << " " << stok.patates << " " << stok.sogan << " " << stok.domates << " " << stok.patlican << " " << stok.havuc << " " << stok.biber << " " << stok.salatalik << " "
 << stok.limon << " " << stok.fasulye << " " << stok.kabak << " " << stok.sarimsak << " " << stok.lahana << " " << stok.pirasa << " " << stok.brokoli << " " << stok.muz << " "
 << stok.silor << " " << stok.turp <<  " " << stok.ispanak << " " << stok.kereviz << " " << stok.karnabahar << " " << stok.semizotu << " " << stok.lahana << " " << stok.kabak << " " << stok.portakal << " "
 << stok.cilek << " " << stok.erik << " " << stok.elma << " " << stok.karpuz << " " << stok.kavun << " " << stok.armut << " " << stok.mandalina << " " << stok.kivi << " " << stok.uzum << " "
 << stok.nektarin << " " << stok.nar << " " << stok.avakado << " " << stok.seftali << " " << stok.greyfurt << " ";
}

//Sýfýrlama

void fiyatsifirla(urunler& fiyat)
{
 fiyat.mantar = 0;
 fiyat.patates = 0;
 fiyat.sogan =  0;
 fiyat.domates = 0;
 fiyat.patlican = 0;
 fiyat.havuc = 0;
 fiyat.biber = 0;
 fiyat.salatalik = 0;
 fiyat.limon = 0;
 fiyat.fasulye = 0;
 fiyat.kabak = 0;
 fiyat.sarimsak = 0;
 fiyat.lahana = 0;
 fiyat.pirasa = 0;
 fiyat.brokoli = 0;
 fiyat.muz = 0;
 fiyat.silor = 0;
 fiyat.turp = 0;
 fiyat.ispanak = 0;
 fiyat.kereviz = 0;
 fiyat.karnabahar = 0;
 fiyat.semizotu = 0;
 fiyat.lahana = 0;
 fiyat.kabak = 0;
 fiyat.portakal = 0;
 fiyat.cilek =  0;
 fiyat.erik = 0;
 fiyat.elma = 0;
 fiyat.karpuz = 0;
 fiyat.kavun = 0;
 fiyat.armut = 0;
 fiyat.mandalina = 0;
 fiyat.kivi = 0;
 fiyat.uzum = 0;
 fiyat.nektarin = 0;
 fiyat.nar = 0;
 fiyat.avakado = 0;
 fiyat.seftali = 0;
 fiyat.greyfurt = 0;
 
   ofstream yaz("fiyatlistesi.txt");
 yaz << fiyat.mantar << " " << fiyat.patates << " " << fiyat.sogan << " " << fiyat.domates << " " << fiyat.patlican << " " << fiyat.havuc << " " << fiyat.biber << " " << fiyat.salatalik << " "
 << fiyat.limon << " " << fiyat.fasulye << " " << fiyat.kabak << " " << fiyat.sarimsak << " " << fiyat.lahana << " " << fiyat.pirasa << " " << fiyat.brokoli << " " << fiyat.muz << " "
 << fiyat.silor << " " << fiyat.turp <<  " " << fiyat.ispanak << " " << fiyat.kereviz << " " << fiyat.karnabahar << " " << fiyat.semizotu << " " << fiyat.lahana << " " << fiyat.kabak << " " << fiyat.portakal << " "
 << fiyat.cilek << " " << fiyat.erik << " " << fiyat.elma << " " << fiyat.karpuz << " " << fiyat.kavun << " " << fiyat.armut << " " << fiyat.mandalina << " " << fiyat.kivi << " " << fiyat.uzum << " "
 << fiyat.nektarin << " " << fiyat.nar << " " << fiyat.avakado << " " << fiyat.seftali << " " << fiyat.greyfurt << " ";
    
}

//Sýfýrlama

void alissifirla(urunler& alis)
{
 
 alis.mantar = 0;
 alis.patates = 0;
 alis.sogan =  0;
 alis.domates = 0;
 alis.patlican = 0;
 alis.havuc = 0;
 alis.biber = 0;
 alis.salatalik = 0;
 alis.limon = 0;
 alis.fasulye = 0;
 alis.kabak = 0;
 alis.sarimsak = 0;
 alis.lahana = 0;
 alis.pirasa = 0;
 alis.brokoli = 0;
 alis.muz = 0;
 alis.silor = 0;
 alis.turp = 0;
 alis.ispanak = 0;
 alis.kereviz = 0;
 alis.karnabahar = 0;
 alis.semizotu = 0;
 alis.lahana = 0;
 alis.kabak = 0;
 alis.portakal = 0;
 alis.cilek =  0;
 alis.erik = 0;
 alis.elma = 0;
 alis.karpuz = 0;
 alis.kavun = 0;
 alis.armut = 0;
 alis.mandalina = 0;
 alis.kivi = 0;
 alis.uzum = 0;
 alis.nektarin = 0;
 alis.nar = 0;
 alis.avakado = 0;
 alis.seftali = 0;
 alis.greyfurt = 0;
 
   ofstream yaz2("alislistesi.txt");
 yaz2 << alis.mantar << " " << alis.patates << " " << alis.sogan << " " << alis.domates << " " << alis.patlican << " " << alis.havuc << " " << alis.biber << " " << alis.salatalik << " "
 << alis.limon << " " << alis.fasulye << " " << alis.kabak << " " << alis.sarimsak << " " << alis.lahana << " " << alis.pirasa << " " << alis.brokoli << " " << alis.muz << " "
 << alis.silor << " " << alis.turp <<  " " << alis.ispanak << " " << alis.kereviz << " " << alis.karnabahar << " " << alis.semizotu << " " << alis.lahana << " " << alis.kabak << " " << alis.portakal << " "
 << alis.cilek << " " << alis.erik << " " << alis.elma << " " << alis.karpuz << " " << alis.kavun << " " << alis.armut << " " << alis.mandalina << " " << alis.kivi << " " << alis.uzum << " "
 << alis.nektarin << " " << alis.nar << " " << alis.avakado << " " << alis.seftali << " " << alis.greyfurt << " ";
   
                   
}

//Sýfýrlama

void stoksifirla(urunler& stok)
{


 stok.mantar = 0;
 stok.patates = 0;
 stok.sogan =  0;
 stok.domates = 0;
 stok.patlican = 0;
 stok.havuc = 0;
 stok.biber = 0;
 stok.salatalik = 0;
 stok.limon = 0;
 stok.fasulye = 0;
 stok.kabak = 0;
 stok.sarimsak = 0;
 stok.lahana = 0;
 stok.pirasa = 0;
 stok.brokoli = 0;
 stok.muz = 0;
 stok.silor = 0;
 stok.turp = 0;
 stok.ispanak = 0;
 stok.kereviz = 0;
 stok.karnabahar = 0;
 stok.semizotu = 0;
 stok.lahana = 0;
 stok.kabak = 0;
 
 stok.portakal = 0;
 stok.cilek =  0;
 stok.erik = 0;
 stok.elma = 0;
 stok.karpuz = 0;
 stok.kavun = 0;
 stok.armut = 0;
 stok.mandalina = 0;
 stok.kivi = 0;
 stok.uzum = 0;
 stok.nektarin = 0;
 stok.nar = 0;
 stok.avakado = 0;
 stok.seftali = 0;
 stok.greyfurt = 0;
 
     ofstream yaz3("stoklistesi.txt");
 yaz3 << stok.mantar << " " << stok.patates << " " << stok.sogan << " " << stok.domates << " " << stok.patlican << " " << stok.havuc << " " << stok.biber << " " << stok.salatalik << " "
 << stok.limon << " " << stok.fasulye << " " << stok.kabak << " " << stok.sarimsak << " " << stok.lahana << " " << stok.pirasa << " " << stok.brokoli << " " << stok.muz << " "
 << stok.silor << " " << stok.turp <<  " " << stok.ispanak << " " << stok.kereviz << " " << stok.karnabahar << " " << stok.semizotu << " " << stok.lahana << " " << stok.kabak << " " << stok.portakal << " "
 << stok.cilek << " " << stok.erik << " " << stok.elma << " " << stok.karpuz << " " << stok.kavun << " " << stok.armut << " " << stok.mandalina << " " << stok.kivi << " " << stok.uzum << " "
 << stok.nektarin << " " << stok.nar << " " << stok.avakado << " " << stok.seftali << " " << stok.greyfurt << " "; 
  
       
}

//Sýfýrlama

void kazancsifirla(urunler& kazanc)
{
 
 kazanc.mantar = 0;
 kazanc.patates = 0;
 kazanc.sogan =  0;
 kazanc.domates = 0;
 kazanc.patlican = 0;
 kazanc.havuc = 0;
 kazanc.biber = 0;
 kazanc.salatalik = 0;
 kazanc.limon = 0;
 kazanc.fasulye = 0;
 kazanc.kabak = 0;
 kazanc.sarimsak = 0;
 kazanc.lahana = 0;
 kazanc.pirasa = 0;
 kazanc.brokoli = 0;
 kazanc.muz = 0;
 kazanc.silor = 0;
 kazanc.turp = 0;
 kazanc.ispanak = 0;
 kazanc.kereviz = 0;
 kazanc.karnabahar = 0;
 kazanc.semizotu = 0;
 kazanc.lahana = 0;
 kazanc.kabak = 0;
 
 kazanc.portakal = 0;
 kazanc.cilek =  0;
 kazanc.erik = 0;
 kazanc.elma = 0;
 kazanc.karpuz = 0;
 kazanc.kavun = 0;
 kazanc.armut = 0;
 kazanc.mandalina = 0;
 kazanc.kivi = 0;
 kazanc.uzum = 0;
 kazanc.nektarin = 0;
 kazanc.nar = 0;
 kazanc.avakado = 0;
 kazanc.seftali = 0;
 kazanc.greyfurt = 0;
 
     ofstream yaz4("kazanclistesi.txt");
 yaz4 << kazanc.mantar << " " << kazanc.patates << " " << kazanc.sogan << " " << kazanc.domates << " " << kazanc.patlican << " " << kazanc.havuc << " " << kazanc.biber << " " << kazanc.salatalik << " "
 << kazanc.limon << " " << kazanc.fasulye << " " << kazanc.kabak << " " << kazanc.sarimsak << " " << kazanc.lahana << " " << kazanc.pirasa << " " << kazanc.brokoli << " " << kazanc.muz << " "
 << kazanc.silor << " " << kazanc.turp <<  " " << kazanc.ispanak << " " << kazanc.kereviz << " " << kazanc.karnabahar << " " << kazanc.semizotu << " " << kazanc.lahana << " " << kazanc.kabak << " " << kazanc.portakal << " "
 << kazanc.cilek << " " << kazanc.erik << " " << kazanc.elma << " " << kazanc.karpuz << " " << kazanc.kavun << " " << kazanc.armut << " " << kazanc.mandalina << " " << kazanc.kivi << " " << kazanc.uzum << " "
 << kazanc.nektarin << " " << kazanc.nar << " " << kazanc.avakado << " " << kazanc.seftali << " " << kazanc.greyfurt << " "; 
   
     
}

//Sýfýrlama

void ayarlarsifirla()
{

minn = 0;
maks = 0;
minmaks = 0;
maksmaks = 0;

 
 ofstream yaz5("ayarlar.txt");
 yaz5 << minmaks << " " << minn << " " << maks << " " << maksmaks << " ";    
}

// .... - - .--. ... ---... -..-. -..-. .... .- -.-. -.- . .-. - -.-- .--. . .-. .-.-.- -.-. --- -- -..-. 
