#include <iostream>
#include <new>
using namespace std;

void DeclaracionArr (int Col, int Fil, int *Arr[]){
	
	  for (int i = 0; i < Col; i++){
		
		Arr[i] = new(nothrow)  int [Fil];
		
		if (Arr[i] == 0) { // Dirección nula
			
			cout << "Fallo de Reserva de Espacio" << endl;
			
		}
		
	}

	
}

void LiberacionMem(int Col, int Fil, int* Arr[]){
	
	for (int i = 0; i<Col; i++){
		
		delete Arr[i];
	}
}

void Impresion (int Al, int Bugs, int *Arr[]){
	
	cout << Arr[0][Al] << endl;
	
	if( Arr[0][Al] < Arr[0][Bugs]){
		
		cout << "Al Kaholic es el mejor" << endl;
		
	}else{
		
		cout << "Mandale un regalito de San Valentin" << endl;
	}
}

int main() {
	
	freopen("salida.txt", "w", stdout);
	
	int Jugadores, Rondas, IA, IB, contador;
	
	cin >> Jugadores;
	cin >> Rondas;
	cin >> IA;
	cin >> IB;

	IA= IA-1;
	IB= IB-1;
	
	int * ArrPtr[Jugadores];
	
	DeclaracionArr(Jugadores, Rondas, ArrPtr);
	
	
	for (int i = 0; i<Jugadores; i++){
		
		for(int j = 0; j< Rondas; j++){
			
			cin >> ArrPtr[i][j];
		}
	}
	
	int * ArrRe[Jugadores];
	
	DeclaracionArr(Jugadores, Rondas, ArrRe);
	
	for(int k = 0; k<Rondas; k++){
		
		for(int i = 0; i<Jugadores; i++){
			
			contador= 12;
			
			for(int j = 0; j<Jugadores; j++){
				
				if (ArrPtr[i][k]<ArrPtr[j][k]){
					
					contador = contador - 3;
				}
			}
			
			if (contador < 0){
				
				contador = 0;
			}
			
			ArrRe[i][k]= contador;
		}
	
	}
	
	LiberacionMem(Jugadores, Rondas, ArrPtr);
	
	DeclaracionArr(1, Jugadores,ArrPtr);
	
	for( int i=0; i<Jugadores; i++){
		
		contador = 0;
		
		for ( int j =0; j<Rondas; j++){
			
				contador = contador + ArrRe[i][j];
		}
		
		ArrPtr[0][i]= contador;
		
	}

	
	LiberacionMem(Jugadores, Rondas, ArrRe);
	
	DeclaracionArr(1, Jugadores, ArrRe);
	
	for (int i=0; i<Jugadores; i++){
		
		contador = 1;
		
		for (int j =0; j<Jugadores; j++){
			
			if (ArrPtr[0][i] < ArrPtr[0][j]){
				
				contador = contador + 1;
				
			}else{
				if (ArrPtr[0][i] == ArrPtr[0][j]){
					
					if (i > j){
						
						contador= contador +1;
					}
				}
			}
		}
		
		ArrRe[0][i]= contador;
	}
	
	LiberacionMem(1, Jugadores, ArrPtr);
	
	Impresion (IA, IB, ArrRe);
		
}


