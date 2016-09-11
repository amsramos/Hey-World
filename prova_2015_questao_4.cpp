#include <stdio.h>

main(){
	// Como serão 1000 posições, partindo da posição 1, os vetores terão 1001 posições, assim descartando a posição 0.
	int fita[1001], pos[1001], preenchidos, p = 0, dias = 0, completo = 0, y = 0;
	//Recebendo as gotas nas posições inseridas pelo usuário
	do{
		p++; // Partindo da posição 1 e incrementando + 1 a cada repetição.
		scanf("%d", &pos[p]); // Recebendo a posição da gota e armezenando em outro vetor.
		if(pos[p] > 0 && pos[p] <= 1000){ // A posição tem que está entre 1 e 1000.
			fita[pos[p]] = 1; // Caso seja verdadeira a condição, a gota cairá na posição recebida (O número 1 representará a gota).
		}
	} while(pos[p] > 0 && pos[p] <= 1000); // O WHILE continuará enquanto a posição da gota estiver entre 1 e 1000.
	 
	 preenchidos = p; // Essa variável será o contador de quantas posições foram preenchidas. E já se inicia com quantidade de gotas pingadas.
	 
	while(preenchidos < 1000){ // O WHILE continuará até que todas as posições sejam preenchidas.
		y++; // Incrementador que ajudará a verificar todas as posições, partindo das primeiras gotas.
		int aux = p; // Para que o valor de p não seja alterado, usarei uma nova variável para auxiliar no caso.
		for(int z = 0; z < p && preenchidos < 1000; z++){ // Esse FOR irá se repetir o número de vezes da quantidade de gotas pingadas na fita, durante todo WHILE.
			
			if(fita[pos[aux] - y] != 1 && pos[aux] - y > 0){ // Se o número da posição da gota pingada menos o valor de y não estiver preenchida...
				fita[pos[aux] - y] = 1; // Preenche-se a posição.
				preenchidos++; // Incrementando 1 nas posições preenchidas.
			}

			if(fita[pos[aux] + y] != 1 && pos[aux] + y <= 1000){ // Se o número da posição da gota pingada mais o valor de y não estiver preenchida...
				fita[pos[aux] + y] = 1; // Preenche-se a posição.
				preenchidos++; // Incrementando 1 nas posições preenchidas.
			}
			aux--; // Descrementando para testar as outras posições.
		}
		dias++;	// Depois de cada FOR, passa-se um dia.
	}
	printf("%d", dias);
}
