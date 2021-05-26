#include<iostream>
using namespace std;
int const filas=4;
int const columnas=5;
void imprimirMatrizBooleanos(bool matriz[filas][columnas]);
void limpiarMatriz(bool disponibilidad[filas][columnas]);
void limpiarMatrizI(int matrizPesos[filas][columnas]);
void mostararDisponibilidad(bool disponibilidad[filas][columnas]);
void imprimirMatrizString(string matriz[filas][columnas]);	
void imprimirMatrizInt(int matriz[filas][columnas]);
float calcularOcupacion(bool disponibilidad[filas][columnas]);
int valorRecaudado(bool disponibilidad[filas][columnas],int contadorEconomicos,int contadorPremium);
void reporteMarcas(string matrizMarcas[filas][columnas]);
float promedioPeso(int matrizPesos[filas][columnas],int contadorContenedores);
void listadoMarcasEconomica(string matrizMarcas[filas][columnas],string vector[]);



int main(){
	//matrices a utilizar 
	string nombrePuerto[filas][columnas];
	bool disponibilidad[filas][columnas];
	string matrizMarcas[filas][columnas];
	string matrizArticulo[filas][columnas];
	int matrizPesos[filas][columnas];
	//------------------------------
	string marcas[columnas];
	int puertos=0;
	int contadorContenedores=0;
	int Ncontenedores=0;
	int columnasD,filaD=0;
	int contadorEconomicos=0;
	int contadorPremium=0;
	
	limpiarMatriz(disponibilidad);
	limpiarMatrizI(matrizPesos);
	cout<<"Ingrese el numero de puertos"<<endl;
	cin>>puertos;
	
	
	for(int i=0;i<puertos;i++){
		cout<<endl;
		cout<<"Bienvenido al puerto "<<i<<endl;
		cout<<endl;
		//matriz disponibilidad
		cout<<endl;
		cout<<"Matriz disponibilidad"<<endl;
		imprimirMatrizBooleanos(disponibilidad);
		cout<<endl;
		cout<<"Las casillas disponibles son"<<endl;
		cout<<endl;
		mostararDisponibilidad(disponibilidad);
		cout<<"Ingrese el numero de contenedores que va cargar"<<endl;
		cin>>Ncontenedores;
		contadorContenedores=contadorContenedores+Ncontenedores;
		int contenedores=0;
		while(contenedores<Ncontenedores){
			contenedores++;
			int coordenadaFila=-1;
			int coordenadaColumna=-1;
			
			cout<<"Ingrese la fila donde desea guardar el contenedor "<<contenedores<<endl;
			cin>>coordenadaFila;
			cout<<endl;
			cout<<"Ingrese la columna donde desea guardar el contenedor "<<contenedores<<endl;
			cin>>coordenadaColumna;
			cout<<endl;
			if(coordenadaColumna>=0 && coordenadaColumna<columnas && coordenadaFila>=0 && coordenadaFila<filas && disponibilidad[coordenadaFila][coordenadaColumna]==1){
			
			cout<<"Ingrese 0 si desea guardar el contenedor en la fila y columna escogida o ingrese 1 si no desea guardar el contenedor "<<endl;
			cin>>disponibilidad[coordenadaFila][coordenadaColumna];
			cout<<endl;
			imprimirMatrizBooleanos(disponibilidad);
			
			cout<<"Ingrese la marca del contenedor "<<endl;
			cout<<endl;
			cin>>matrizMarcas[coordenadaFila][coordenadaColumna];
			
			cout<<endl;
			
			cout<<"Tipo A: Alimentos, Tipo B: Dispositivos electronicos, Tipo C: Ropa y demás textiles"<<endl;
			cout<<endl;
			cout<<"ingrese el tipo de articulo del contenedor"<<endl;
			cin>>matrizArticulo[coordenadaFila][coordenadaColumna];
			
			cout<<endl;
			
			cout<<"ingrese el peso del contenedor "<<endl;
			cin>>matrizPesos[coordenadaFila][coordenadaColumna];
			cout<<endl;

			}else{
				cout<<"La posicion ingresada es invalida"<<endl;
			}
			
		}
		
			
	float ocupacion=calcularOcupacion(disponibilidad);
	cout<<"El porcentaje de ocupacion del barco en el puerto es "<<ocupacion<<endl;
			

}
//impresion de las matrices	
		cout<<"Disponibilidad"<<endl;
		imprimirMatrizBooleanos(disponibilidad);
		cout<<endl;
		cout<<"Marcas"<<endl;
		imprimirMatrizString(matrizMarcas);
		cout<<endl;
		cout<<"Peso"<<endl;
		imprimirMatrizInt(matrizPesos);
		cout<<endl;
		cout<<"tipo Articulo"<<endl;
		imprimirMatrizString(matrizArticulo);
		cout<<endl;
		//------------------------------------
	int valorTotal=valorRecaudado(disponibilidad,contadorEconomicos,contadorPremium);
	cout<<"El valor recaudado es "<<valorTotal<<endl;
	
	cout<<"Se ingresaron "<<contadorContenedores<<" contenedores en todos los puertos"<<endl;
	reporteMarcas(matrizMarcas);
	cout<<endl;
	
	listadoMarcasEconomica(matrizMarcas,marcas);
	
	float promedio=promedioPeso(matrizPesos,contadorContenedores);
	cout<<"El promedio de peso de los contenedores es "<<promedio<<endl;
	
		return 0;
	}

//-------------------------------------------------------------
	//limpiar matriz de disponibilidad
	void limpiarMatriz(bool disponibilidad[filas][columnas]){
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				disponibilidad[i][j]=1;
		}
	}
}
//-------------------------------------------------------------
	//imprimir matrizes de boleanos
	void imprimirMatrizBooleanos(bool matriz[filas][columnas]){
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				cout<<matriz[i][j]<<"\t";
				
			}
			cout<<endl;
		}
	}
	//imprimir casillas de la matriz 
void mostararDisponibilidad(bool disponibilidad[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(disponibilidad[i][j]==1){
				cout<<i<<","<<j<<endl;
				
			}
			
		}
	}
}
	//imprimir matriz de string
	void imprimirMatrizString(string matriz[filas][columnas]){
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				cout<<matriz[i][j]<<"\t";
				
			}
			cout<<endl;
		}
	}
	//imprimir matriz int 
	void imprimirMatrizInt(int matriz[filas][columnas]){
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				cout<<matriz[i][j]<<"\t";
				
				
			}
			cout<<endl;
		}
	}
	//limpiar matriz int
	void limpiarMatrizI(int matrizPesos[filas][columnas]){
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				matrizPesos[i][j]=0;
		}
	}
}
	//informacion solicitada
	void listadoMarcasEconomica(string matrizMarcas[filas][columnas],string vector[columnas]){
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				if(i==0 && j==0 && i==filas && j==columnas ){
					matrizMarcas[i][j]==vector[j];
					cout<<"Las marcas de los contenedores que van en zona economica son "<<vector[j]<<endl;
				}
			}
		}
	}	
	float calcularOcupacion(bool disponibilidad[filas][columnas]){
		float ocupacion=0.0;
		int contadorO=0;
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				if(disponibilidad[i][j]==0){
					contadorO++;
				}
			}
		}
		ocupacion=(contadorO*100)/(filas*columnas);
		return ocupacion;
	}
	int valorRecaudado(bool disponibilidad[filas][columnas],int contadorEconomicos,int contadorPremium){
		int valorTotal=0;
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				if(i==0 && disponibilidad[i][j]==0 && j==0 && i==filas && j==columnas){
				contadorEconomicos++;
			}else{
				contadorPremium=contadorPremium+1;
			}
		}
	}
	valorTotal=(100*contadorEconomicos)+(300*contadorPremium);
	return valorTotal;
}
	void reporteMarcas(string matrizMarcas[filas][columnas]){
		string marcaPA="";
		int contadorEconomicos=0;
		int contadorPremium=0;
		int valorAP=0;

		cout<<"ingrese la marca que va pagar "<<endl;
		cin>>marcaPA;
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				if(i==0 && matrizMarcas[i][j]==marcaPA && j==0 && i==filas && j==columnas ){
				contadorEconomicos++;
			}else{
				contadorPremium=contadorPremium+1;
			}
		}
	}
	valorAP=(100*contadorEconomicos)+(300*contadorPremium);
	cout<<"la empresa "<<marcaPA<<" tiene "<<contadorEconomicos<<" contenedor en la zona economica y "<<contadorPremium<<" en la zona premium. El valor a pagar es de" <<valorAP<<"USD"<<endl; 
	}
	float promedioPeso(int matrizPesos[filas][columnas],int contadorContenedores){
		float promedio=0.0;
		int acomuladorP=0;
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				if(matrizPesos[i][j]>=1){
					acomuladorP=acomuladorP+matrizPesos[i][j];
				}
			}
		}
		promedio=(acomuladorP/contadorContenedores);
		return promedio;
	}
