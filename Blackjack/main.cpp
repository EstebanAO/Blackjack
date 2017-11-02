//
//  main.cpp
//  Blackjack
//
//  Created by Esteban Arocha Ortuño on 10/31/17.
//  Copyright © 2017 EstebanAO. All rights reserved.
//



#include <iostream>
using namespace std;

#include "Mano.h"


//functions
void deal(Deck &deckJuego, Mano &ManoD, Mano &ManoJ)
{
    deckJuego.shuffle();
    ManoJ = *new Mano (deckJuego);
    ManoD = *new Mano (deckJuego);
    
    cout<<"Mano del dealer: "<<endl<<endl;
    ManoD.printD();
    cout<<endl<<endl<<"Mano del jugador: "<<endl<<endl;
    ManoJ.printJ();

}

void hit(Mano &ManoJ,Mano ManoD, Deck &deckJuego, bool &disableOptions, int &score)
{
    cout<<endl<<"Mano del dealer: "<<endl<<endl;
    ManoD.printD();
    
    cout<<endl<<"Mano del jugador: "<<endl<<endl;
    ManoJ.getCarta(deckJuego);
    ManoJ.printJ();
    
    if (ManoJ.getscore() > 21)
    {
        cout<<"Perdiste, tu mano supera 21 puntos"<<endl;
        score--;
        cout<<endl<<"El score es: "<<score<<endl;
        disableOptions = true;
    }
}

void stand(Mano &ManoD, Mano ManoJ, Deck &deckJuego, bool &disableOptions, int &score)
{
    while(
          (ManoD.getMinSumaGanadora() < 17 || ManoD.getMaxSumaGanadora() < 17) &&
          ManoD.getMinSumaGanadora() < ManoJ.getscore() &&
          ManoD.getMaxSumaGanadora() < ManoJ.getscore()
          )
          
    {
        ManoD.getCarta(deckJuego);
    }
    
    if (ManoJ.getscore() > 21)
    {
        cout<<"Perdiste, las cartas del dealer son:"<<endl;
        ManoD.printJ();
        score--;
        cout<<endl<<"El score es: "<<score<<endl;
        
    }
    else if (ManoD.getscore() >= ManoJ.getscore() && ManoD.getscore() <= 21)
    {
        cout<<"Perdiste, las cartas del dealer son:"<<endl;
        ManoD.printJ();
        score--;
        cout<<endl<<"El score es: "<<score<<endl;
    }
    else
    {
        cout<<"Ganaste, las cartas del dealer son:"<<endl;
        ManoD.printJ();
        score++;
        cout<<endl<<"El score es: "<<score<<endl;
    }
    disableOptions = true;
}

int main()
{
    Deck deckJuego;
    Mano manoJ(deckJuego);
    Mano manoD(deckJuego);
    bool disableOptions = false;
    int score = 0;
    
    cout<<"BlackJack:"<<endl<<endl;

    cout<<"============================================"<<endl<<endl;
    deal(deckJuego, manoD, manoJ);
    
    char controller = 'r';
    cout<<endl<<"============================================"<<endl<<endl;
    cout<<"¿Que desea hacer? Hit (h), Deal (d), Stand (s), Salir (e) "<<endl;
    cin>>controller;

    while(controller != 'e')
    {
        switch (controller)
        {
            case 'h':
                if (!disableOptions)
                {
                    hit(manoJ, manoD, deckJuego, disableOptions, score);
                }
                break;
            case 'd':
                disableOptions = false;
                deal(deckJuego, manoD, manoJ);
                break;
            case 's':
                if (!disableOptions)
                {
                    stand(manoD, manoJ, deckJuego, disableOptions, score);
                }
                break;
        }
        if (!disableOptions)
        {
            cout<<endl<<"============================================"<<endl<<endl;
            cout<<"¿Que desea hacer? Hit (h), Deal (d), Stand (s), Salir (e) "<<endl;
        }
        else
        {
            cout<<endl<<"============================================<<endl"<<endl;
            cout<<"Que desea hacer? Deal (d), Salir (e) "<<endl;
        }
        cin>>controller;
    }
    
    return 0;
}

