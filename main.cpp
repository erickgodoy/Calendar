#include <iostream>
#include <stdio.h>
using namespace std;

class Calendario{
private:
    int mes;
    int anio;
public:
    Calendario(){
    }
    void Interfaz(){
    cout<<"Ingrese el Mes: ";
    cin>>mes;
    cout<<"Ingrese el A\xa4o: ";
    cin>>anio;
    MostrarCalendario();
    }
    void MostrarCalendario(){
          cout<<"\nMes: "<<NombreMes(mes)<<"    A\xa4o:"<<anio<<"\n";
          cout<<"Dom Lun Mar Mie Jue Vie Sab\n";
         int z= zeller(anio,mes);
         for(int i=0;i<z;i++){
            cout<<"    ";
         }
          int  diames=CalcularMes(anio,mes);
            for(int dia=1;dia<=diames;dia++){
                printf("%3d ",dia);
                z++;
                if(z % 7==0) cout<<endl;
            }
            cout<<"\n\n";
    }
    int  CalcularMes(int anio,int mes){
        if(mes==1 || mes==3 ||mes==5 ||mes==7 ||mes==8 ||mes==10 || mes==12){return 31;}
     if(mes==2){
            if(esBisiesto(anio)){
                return 29;}
      return 28;}
     return 30;
    }
    bool esBisiesto(int anio){
    if(anio % 4 != 0) return false;
       if(anio % 100 != 0) return true;
          if(anio % 400 != 0) return false;
         return true;
    }
    int zeller(int anio, int mes){
        int a=(14-mes)/12;
        int y=anio-a;
        int m=mes + 12 * a - 2;
        int dia=1,d;
        d=(dia+y+y/4-y/100+y/400+(31*m)/12)%7;
        return d;
            }
    string NombreMes(int mes){
    switch(mes){
case 1: return "Enero";
    case 2:  return "Febrero";
        case 3:  return "Marzo";
            case 4: return "Abril";
                case 5: return "Mayo";
                    case 6: return "Junio";
                        case 7: return "Julio";
                            case 8: return "Agosto";
                                case 9: return "Septiembre";
                                    case 10: return "Octubre";
                                        case 11: return "Noviembre";
                                            case 12: return "Diciembre";
    }}

};
int main()
{
 Calendario C;
 C.Interfaz();
}
