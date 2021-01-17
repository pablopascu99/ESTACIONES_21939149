#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main() {
    string municipio;
    int cp, poblacion, altura, superficie;
    //float renta, nota;
    ifstream fin("../parcialPEL.tsv");//Declaramos fin como variable de entrada
    int contadorMunicipios=0;
    int promedioAltura=0;
    int alturaMax=0;
    int alturaMin=99999;
    int poblacionAlta=0;
    int poblacionBaja=99999;
    double mayorDensidad=0.0;
    double menorDensidad=99999.99;
    int poblacionAvila=0;
    int cont=0;
    string municipioAlto,municipioBajo,municipioMasPoblado,municipioMenosPoblado,municipioMasDensidad,municipioMenosDensidad;
    try{ // Declaro inicio del bloque que pudiese generar alguna excepcion
        while(!fin.eof()){
            //Definimos el orden en el que se seguirá la estructura
            int cp;
            fin>>cp>>municipio>>poblacion>>altura>>superficie;
            getline(fin,cp,',');
            //Contamos los municipios de Avila
            contadorMunicipios++;
            //Calculamos el promedio de altura
            promedioAltura=promedioAltura+altura;
            //Calculamos el municipio con la altura mas alta
            if(alturaMax<=altura){
                alturaMax=altura;
                municipioAlto=municipio;
            }
            //Calculamos el municipio con la altura mas baja
            if(alturaMin>=altura){
                alturaMin=altura;
                municipioBajo=municipio;
            }
            //Calculamos el municipio mas poblado
            if(poblacionAlta<=poblacion){
                poblacionAlta=poblacion;
                municipioMasPoblado=municipio;
            }
            //Calculamos el municipio menos poblado
            if(poblacionBaja>=poblacion){
                poblacionBaja=poblacion;
                municipioMenosPoblado=municipio;
            }
            //Calculamos el municipio con mas densidad de poblacion
            double densidad=(double)poblacion/(double)superficie;
            if(mayorDensidad<=densidad){
                mayorDensidad=densidad;
                municipioMasDensidad=municipio;
            }
            //Calculamos el municipio con mas densidad de poblacion
            densidad=(double)poblacion/(double)superficie;
            if(menorDensidad>=densidad){
                menorDensidad=densidad;
                municipioMenosDensidad=municipio;
            }
            //Calculamos la poblacion de Avila para saber como de mayor es la poblacion en Madrid que en Avila
            poblacionAvila=poblacionAvila+poblacion;
            //Calculamos cuales son los municipios con mas de 40 habitantes y esten a mas de 900 metros de altura
            if(poblacion>=40 && altura>900 && cont<10){
                cont++;
                cout<<municipio<<"Tiene al menos 40 habitantes y 900 metros o mas de altura"<<endl;
            }
        }
        cout<<"Ejercicio 1"<<endl;
        cout<<"Hay "<<contadorMunicipios<<" municipios"<<endl;
        cout<<"Ejercicio 2"<<endl;
        cout<<"El promedio de altura es: "<<(double)promedioAltura/(double)contadorMunicipios<<endl;
        cout<<"Ejercicio 3"<<endl;
        cout<<"El municipio con la altura mas alta es: "<<municipioAlto<<endl;
        cout<<"Ejercicio 4"<<endl;
        cout<<"El municipio con la altura mas baja es: "<<municipioBajo<<endl;
        cout<<"Ejercicio 5"<<endl;
        cout<<"El municipio con la poblacion mas alta es: "<<municipioMasPoblado<<endl;
        cout<<"Ejercicio 6"<<endl;
        cout<<"El municipio con la poblacion mas baja es: "<<municipioMenosPoblado<<endl;
        cout<<"Ejercicio 7"<<endl;
        cout<<"El municipio con la densidad mas alta es: "<<municipioMasDensidad<<endl;
        cout<<"Ejercicio 8"<<endl;
        cout<<"El municipio con la densidad mas baja es: "<<municipioMenosDensidad<<endl;
        cout<<"Ejercicio 9"<<endl;
        cout<<"Madrid es mas grande que Avila por "<<6507184/(double)poblacionAvila<<" veces proporcionalmente"<<endl;
    }
        //Cerramos archivo .tsv
    catch(...){//Captura todas las excepciones posibles para no romper el program de forma descontrolada.
        fin.close();
    }
}