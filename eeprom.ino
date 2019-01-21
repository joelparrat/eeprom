
//
// rempli l'eeprom la premiere fois avant l'installation de ard.ino
// eeprom	 0.1
// ard		 0.1
// protocole 0.1
//
// ATTENTION: passer en 115200
//
// fait clignoter le voyant avant l'ecriture de l'eeprom
// eclaire le voyant pendant l'ecriture
// eteint  le voyant apres   l'ecriture
//
//*
//* ATTENTION en decimale
//* ATTENTION adresse des capteurs de temperature NE SONT PLUS dans l'eeprom
//* ATTENTION en debut d'eeprom info 0-31 (actuellement utilise 0-17)
//* ATTENTION debut table srt a l'adresse 32 (decimale)
//*
//
//* programmes concernes
//* ard.ino
//* ard
//* ardcmm
//* ardprm
//* ardsrv
//* ardwnd
//* ardweb
//* ardsml
//
//*
//* ITP IBR IHM ILM IHX ILX OTP OBR OHM OLM OHX OLX NEN NCP NSR RSV
//*
//* ITP: input  type   		> NO=0 DGT=1 ANL=2 OWR=4 INT=8 I2C=16 ...
//* IBR: input  broche 		> 0-255
//* IHM: input  hight  mini 	> 0-3
//* ILM: input  low    mini	> 0-255
//* IHX: input  hight  maxi 	> 0-3
//* ILX: input  low    maxi	> 0-255
//* OTP: output type   		> NO=0 OFF=1 ON=2 DGT=4 PWM=8 ...
//* OBR: output broche 		> 0-255
//* OHM: output hight  mini 	> 0-3
//* OLM: output low    mini	> 0-255
//* OHX: output hight  maxi 	> 0-3
//* OLX: output low    maxi	> 0-255
//* NEN: nom de l'entre
//* NCP: nom du capteur
//* NSR: nom de la sortie
//* RSV: reserve
//*
//

#include <EEPROM.h>

#define PD13 13		// pin D13 Sortie numerique voyant carte

void setup()
{
	char i;
	
	Serial.begin(115200);
	pinMode(PD13,	OUTPUT);

	for (i=0; i<60; i++)
	{
		digitalWrite(PD13, !digitalRead(PD13));																			// cligno voyant carte (D13)
		delay(500);
	}
	digitalWrite(PD13, LOW);																							// eclaire voyant carte (D13)

	EEPROM.write(0, 'J');	// copywrite
	EEPROM.write(1, 'o');
	EEPROM.write(2, 'e');
	EEPROM.write(3, 'l');
	EEPROM.write(4, 'P');
	EEPROM.write(5, '.');
	
	EEPROM.write(6,  'A');	// application
	EEPROM.write(7,  'R');
	EEPROM.write(8,  'D');
	EEPROM.write(9,  ' ');
	EEPROM.write(10, ' ');
	EEPROM.write(11, ' ');
	
	EEPROM.write(12, '0');	// version eeprom
	EEPROM.write(13, '1');
	EEPROM.write(14, '0');	// version ard.ino
	EEPROM.write(15, '1');
	EEPROM.write(16, '0');	// version protocole
	EEPROM.write(17, '1');
	
//*
//* sortie 0 lbt
//*

	EEPROM.write(32, 2);
	EEPROM.write(33, 7);
	EEPROM.write(34, 0);
	EEPROM.write(35, 50);
	EEPROM.write(36, 3);
	EEPROM.write(37, 32);
	EEPROM.write(38, 8);
	EEPROM.write(39, 3);
	EEPROM.write(40, 0);
	EEPROM.write(41, 200);
	EEPROM.write(42, 0);
	EEPROM.write(43, 20);
	EEPROM.write(44, 1);
	EEPROM.write(45, 1);
	EEPROM.write(46, 1);
//	EEPROM.write(47, 255);

//*
//* sortie 1 vbt
//*

	EEPROM.write(48, 4);
	EEPROM.write(49, 0);
//* en temperature les valeurs sont multipliees par 4 (20 -> 80));
	EEPROM.write(50, 0);
	EEPROM.write(51, 80);
//* en temperature les valeurs sont multipliees par 4 (30 -> 120));
	EEPROM.write(52, 0);
	EEPROM.write(53, 120);
	EEPROM.write(54, 8);
	EEPROM.write(55, 5);
	EEPROM.write(56, 0);
	EEPROM.write(57, 50);
	EEPROM.write(58, 0);
	EEPROM.write(59, 200);
	EEPROM.write(60, 2);
	EEPROM.write(61, 2);
	EEPROM.write(62, 2);
//	EEPROM.write(63, 255);

//*
//* sortie 2 vr1
//*

	EEPROM.write(64, 4);
	EEPROM.write(65, 0);
//* en temperature les valeurs sont multipliees par 4 (30 -> 120));
	EEPROM.write(66, 0);
	EEPROM.write(67, 120);
//* en temperature les valeurs sont multipliees par 4 (50 -> 200));
	EEPROM.write(68, 0);
	EEPROM.write(69, 200);
	EEPROM.write(70, 8);
	EEPROM.write(71, 6);
	EEPROM.write(72, 0);
	EEPROM.write(73, 70);
	EEPROM.write(74, 0);
	EEPROM.write(75, 200);
	EEPROM.write(76, 3);
	EEPROM.write(77, 2);
	EEPROM.write(78, 3);
//	EEPROM.write(79, 255);

//*
//* sortie 3 vr2
//*

	EEPROM.write(80, 4);
	EEPROM.write(81, 0);
//* en temperature les valeurs sont multipliees par 4 (30 -> 120));
	EEPROM.write(82, 0);
	EEPROM.write(83, 120);
//* en temperature les valeurs sont multipliees par 4 (50 -> 200));
	EEPROM.write(84, 0);
	EEPROM.write(85, 200);
	EEPROM.write(86, 8);
	EEPROM.write(87, 9);
	EEPROM.write(88, 0);
	EEPROM.write(89, 50);
	EEPROM.write(90, 0);
	EEPROM.write(91, 200);
	EEPROM.write(92, 4);
	EEPROM.write(93, 2);
	EEPROM.write(94, 4);
//	EEPROM.write(95, 255);

//*
//* sortie 4 pr1
//*

	EEPROM.write(96, 4);
	EEPROM.write(97, 0);
//* en temperature les valeurs sont multipliees par 4 (30 -> 120));
	EEPROM.write(98, 0);
	EEPROM.write(99, 120);
//* en temperature les valeurs sont multipliees par 4 (50 -> 200));
	EEPROM.write(100, 0);
	EEPROM.write(101, 200);
	EEPROM.write(102, 8);
	EEPROM.write(103, 10);
	EEPROM.write(104, 0);
	EEPROM.write(105, 50);
	EEPROM.write(106, 0);
	EEPROM.write(107, 200);
	EEPROM.write(108, 5);
	EEPROM.write(109, 2);
	EEPROM.write(110, 5);
//	EEPROM.write(111, 255);

//*
//* sortie 5 pr2
//*

	EEPROM.write(112, 4);
	EEPROM.write(113, 0);
//* en temperature les valeurs sont multipliees par 4 (30 -> 120));
	EEPROM.write(114, 0);
	EEPROM.write(115, 120);
//* en temperature les valeurs sont multipliees par 4 (50 -> 200));
	EEPROM.write(116, 0);
	EEPROM.write(117, 200);
	EEPROM.write(118, 8);
	EEPROM.write(119, 11);
	EEPROM.write(120, 0);
	EEPROM.write(121, 50);
	EEPROM.write(122, 0);
	EEPROM.write(123, 200);
	EEPROM.write(124, 6);
	EEPROM.write(125, 2);
	EEPROM.write(126, 6);
//	EEPROM.write(127, 255);

//*
//* sortie 6 ldb
//*

	EEPROM.write(128, 4);
	EEPROM.write(129, 0);
//* en temperature les valeurs sont multipliees par 4 (20 -> 80));
	EEPROM.write(130, 0);
	EEPROM.write(131, 80);
//* en temperature les valeurs sont multipliees par 4 (20 -> 80));
	EEPROM.write(132, 0);
	EEPROM.write(133, 80);
	EEPROM.write(134, 4);
	EEPROM.write(135, 14);
	EEPROM.write(136, 3);
	EEPROM.write(137, 255);
	EEPROM.write(138, 0);
	EEPROM.write(139, 00);
	EEPROM.write(140, 2);
	EEPROM.write(141, 2);
	EEPROM.write(142, 7);
//	EEPROM.write(143, 255);

//*
//* sortie 7 ldv
//*

	EEPROM.write(144, 4);
	EEPROM.write(145, 0);
//* en temperature les valeurs sont multipliees par 4 (20 -> 80));
	EEPROM.write(146, 0);
	EEPROM.write(147, 80);
//* en temperature les valeurs sont multipliees par 4 (25 -> 100));
	EEPROM.write(148, 0);
	EEPROM.write(149, 100);
	EEPROM.write(150, 4);
	EEPROM.write(151, 15);
	EEPROM.write(152, 3);
	EEPROM.write(153, 255);
	EEPROM.write(154, 3);
	EEPROM.write(155, 255);
	EEPROM.write(156, 2);
	EEPROM.write(157, 2);
	EEPROM.write(158, 8);
//	EEPROM.write(159, 255);

//*
//* sortie 8 ldr
//*

	EEPROM.write(160, 4);
	EEPROM.write(161, 0);
//* en temperature les valeurs sont multipliees par 4 (25 -> 100));
	EEPROM.write(162, 0);
	EEPROM.write(163, 100);
//* en temperature les valeurs sont multipliees par 4 (25 -> 100));
	EEPROM.write(164, 0);
	EEPROM.write(165, 100);
	EEPROM.write(166, 4);
	EEPROM.write(167, 16);
	EEPROM.write(168, 0);
	EEPROM.write(169, 0);
	EEPROM.write(170, 3);
	EEPROM.write(171, 255);
	EEPROM.write(172, 2);
	EEPROM.write(173, 2);
	EEPROM.write(174, 9);
//	EEPROM.write(175, 255);

//*
//* sortie 9 err
//*

	EEPROM.write(176, 2);
	EEPROM.write(177, 6);
	EEPROM.write(178, 0);
	EEPROM.write(179, 80);
	EEPROM.write(180, 0);
	EEPROM.write(181, 80);
	EEPROM.write(182, 4);
	EEPROM.write(183, 4);
	EEPROM.write(184, 3);
	EEPROM.write(185, 255);
	EEPROM.write(186, 0);
	EEPROM.write(187, 0);
	EEPROM.write(188, 7);
	EEPROM.write(189, 3);
	EEPROM.write(190, 10);
//	EEPROM.write(191, 255);

//*
//* sortie 10 pmp
//*

	EEPROM.write(192, 1);
	EEPROM.write(193, 2);
	EEPROM.write(194, 0);
	EEPROM.write(195, 0);
	EEPROM.write(196, 3);
	EEPROM.write(197, 255);
	EEPROM.write(198, 4);
	EEPROM.write(199, 17);
	EEPROM.write(200, 0);
	EEPROM.write(201, 0);
	EEPROM.write(202, 3);
	EEPROM.write(203, 255);
	EEPROM.write(204, 8);
	EEPROM.write(205, 4);
	EEPROM.write(206, 11);
//	EEPROM.write(207, 255);

//*
//* sortie 11 src, no
//* sortie 12 srd, no
//* sortie 13 sre, no
//*

	EEPROM.write(214, 0);
	EEPROM.write(230, 0);
	EEPROM.write(246, 0);
	
	digitalWrite(PD13, HIGH);																							// eteint voyant carte (D13)
}

void loop()
{
	int  li;
	char lc;
	
	for (li=0; li<256; li++)
	{
		lc = EEPROM.read(li);
		Serial.print(li);
		Serial.write("=");
		Serial.println(lc, DEC);
	}
	
	delay(10000);
}

