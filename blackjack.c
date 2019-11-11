#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Kortti
{
	char vari;
	char rivi;
	char arvo;
	int pelaa;
};
int
main ()
{
	struct Kortti kavio[5][52];
	char Rivit[13] =
	{ '1', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'V', 'D', 'R' };
	int i, j;
	int ansiot = 10;
	srand (time (0));
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 13; j++)
		{
			kavio[i][j].vari = 'T';
			kavio[i][j].rivi = Rivit[j];
			kavio[i][j].arvo = j + 1;
			kavio[i][j].pelaa = 0;
		}
		for (j = 13; j < 26; j++)
		{
			kavio[i][j].vari = 'P';
			kavio[i][j].rivi = Rivit[j - 13];
			kavio[i][j].arvo = j - 12;
			kavio[i][j].pelaa = 0;
		}
		for (j = 26; j < 39; j++)
		{
			kavio[i][j].vari = 'K';
			kavio[i][j].rivi = Rivit[j - 26];
			kavio[i][j].arvo = j - 25;
			kavio[i][j].pelaa = 0;
		}
		for (j = 39; j < 52; j++)
		{
			kavio[i][j].vari = 'C';
			kavio[i][j].rivi = Rivit[j - 39];
			kavio[i][j].arvo = j - 38;
			kavio[i][j].pelaa = 0;
		}
	}
	printf ("Tervetuloa meidan poytaan\n");
	printf ("Voittosumma %d\n\n", ansiot);
	while (ansiot > 0)
	{
		int pelaajan_kokonaisarvo = 0;
		int saldo_kokonaisarvo = 0;
		char jatkaa = 'k';
		int veto = 0;
		printf ("Kuinka paljon panostat?\n");
		scanf ("%d", &veto);
		while (veto > ansiot)
		{
			printf ("Sinulla ei ole paljon rahaa\n");
			printf ("Kuinka paljon panostat?\n");
			scanf ("%d", &veto);
		}
		printf ("Jakelu kortit...\n\n");
		int peli_Kortti = rand () % 5;
		int asetus_Kortti = rand () % 52;
		kavio[peli_Kortti][asetus_Kortti].pelaa = 1;
		printf ("Saldo: vari %c rivi %c\n",
			kavio[peli_Kortti][asetus_Kortti].vari,
			kavio[peli_Kortti][asetus_Kortti].rivi);
		saldo_kokonaisarvo = kavio[peli_Kortti][asetus_Kortti].arvo;
		printf ("saldo kokonaisarvo: %d\n\n", saldo_kokonaisarvo);
		int ok;
		for (i = 0; i < 2; i++)
		{
			ok = 0;
			while (!ok)
			{
				peli_Kortti = rand () % 5;
				asetus_Kortti = rand () % 52;
				if (kavio[peli_Kortti][asetus_Kortti].pelaa == 0)
				{
					ok = 1;
					kavio[peli_Kortti][asetus_Kortti].pelaa = 1;
					pelaajan_kokonaisarvo =
					pelaajan_kokonaisarvo +
					kavio[peli_Kortti][asetus_Kortti].arvo;
				}
			}
			printf ("Pelaaja : vari %c rivi %c\n",
			kavio[peli_Kortti][asetus_Kortti].vari,
			kavio[peli_Kortti][asetus_Kortti].rivi);
		}
		printf ("pelaajan kokonaisarvo: %d\n\n", pelaajan_kokonaisarvo);
		int lopettaa = 0;
		while (lopettaa == 0)
		{
			if (pelaajan_kokonaisarvo > 20)
			{
				lopettaa = 1;
			}
			else
			{
				printf ("Haluatko uuden kortin? K tai E \n");
				jatkaa = 'a';
				while (!(jatkaa == 'k') && !(jatkaa == 'e'))
				{
					scanf ("%c", &jatkaa);
				}
				if (jatkaa == 'k')
				{
					ok = 0;
					while (!ok)
					{
						peli_Kortti = rand () % 5;
						asetus_Kortti = rand () % 52;
						if (kavio[peli_Kortti][asetus_Kortti].pelaa == 0)
						{
							ok = 1;
							kavio[peli_Kortti][asetus_Kortti].pelaa = 1;
							pelaajan_kokonaisarvo =
							pelaajan_kokonaisarvo +
							kavio[peli_Kortti][asetus_Kortti].arvo;
						}
					}
					printf ("\nPelaaja : vari %c rivi %c\n",
					kavio[peli_Kortti][asetus_Kortti].vari,
					kavio[peli_Kortti][asetus_Kortti].rivi);
					printf ("pelaajan kokonaisarvo : %d\n\n",
					pelaajan_kokonaisarvo);
				}
				if (jatkaa == 'e')
				{
					lopettaa = 1;
				}
			}
		}
		
		if (pelaajan_kokonaisarvo > 21)
		{
			printf ("olet havinnyt %d\n\n", veto);
			ansiot = ansiot - veto;
		}
		if (pelaajan_kokonaisarvo == 21)
		{
			veto = 1.5 * veto;
			printf ("BLACKJACK ! Voitit %d\n\n", veto);
			ansiot = ansiot + veto;
		}
		if (pelaajan_kokonaisarvo < 21)
		{
			printf ("\nVetaa saldosta...\n\n");
			while (saldo_kokonaisarvo < 17)
			{
				ok = 0;
				while (!ok)
				{
					peli_Kortti = rand () % 5;
					asetus_Kortti = rand () % 52;
					if (kavio[peli_Kortti][asetus_Kortti].pelaa == 0)
					{
						ok = 1;
						kavio[peli_Kortti][asetus_Kortti].pelaa = 1;
						saldo_kokonaisarvo =
						saldo_kokonaisarvo +
						kavio[peli_Kortti][asetus_Kortti].arvo;
					}
				}
				printf ("Saldo : vari %c rivi %c\n",
				kavio[peli_Kortti][asetus_Kortti].vari,
				kavio[peli_Kortti][asetus_Kortti].rivi);
			}
			printf ("saldon kokonaisarvo : %d\n\n", saldo_kokonaisarvo);
			if (saldo_kokonaisarvo <= 21)
			{
				if (pelaajan_kokonaisarvo > saldo_kokonaisarvo)
				{
					printf ("Saldo on havinnyt\n");
					printf ("Olet voittanut%d\n\n", veto);
					ansiot = ansiot + veto;
				}
				else
				{
					printf ("Saldo on voittanut\n");
					printf ("Olet havinnyt%d\n\n", veto);
					ansiot = ansiot - veto;
				}
			}
			else
			{
				printf ("Saldo on havinnyt\n");
				printf ("Olet voittanut %d\n\n", veto);
				ansiot = ansiot + veto;
			}
		}
		printf ("Tulosi %d\n", ansiot);
		printf ("Haluatko jatkaa? K tai E \n");
		jatkaa = 'a';
		while (jatkaa != 'k')
		{
			printf ("Onnistu!");
			scanf ("%c", &jatkaa);
			if (jatkaa == 'e')
			{
				printf ("Heippa!\n");
				return 0;
			}
		}
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 52; j++)
			{
				kavio[i][j].pelaa = 0;
			}
		}
	}
	printf ("Sinulla ei ole rahaa, heippa!\n");
}