**1-OJI UŽDUOTIS**
Ši programa (suprogramuota C++ programavimo kalba) yra skirta apskaičiuoti studentų pažymius, remiantis jų namų darbų ir egzamino rezultatais.

*Programos veikimas:*
1. Programa leidžia vartotojui pasirinkti, ar duomenys bus suvedami ranka, ar sugeneruojami atsitiktinai. Duomenys - vardas, pavardė, namų darbų pažymys, egzamino pažymys. Papildomai reikia nurodyti kiek studentų bus suvedama ir jų namų darbų skaičių (jis turi būti vienodas).
2. Jei pasirenkama duomenis suvesti ranka, viską vartotojas renka rankiniu būdu, jeigu atsitiktinai - ranka reikia suvesti tik studentų vardus ir pavardes, o pažymiai generuojami atsitiktinai. Abiejais atvejais pirma paklausiama kiek studentų ir namų darbų.
3. Paklausiama, ar galutinio pažymio skaičiavimui norima naudoti namų darbų vidurkį ar medianą, tada atsižvelgiant į pasirinkimą apskaičiuojamas galutinis pažymis remiantis formule - 0.4×nd+0.6×egzaminas.
4. Duomenys išspausdinami ir pabaigoje studento duomenys išvalomi, kad išlaisvintų užimtą atmintį.

*Funkcijos:*
1. ndVidurkis(): apskaičiuoja namų darbų pažymių vidurkį.
2. ndMediana(): apskaičiuoja namų darbų pažymių medianą.
3. galutinis(): apskaičiuoja galutinį pažymį.
4. ivestiDuomenisRanka(): leidžia įvesti duomenis rankiniu būdu.
5. atsitiktiniaiPazymiai(): sugeneruoja atsitiktinius pažymius.
6. spausdinti(): atspausdina studentų duomenis lentelėje (vardas, pavarde, galutinis).
7. valymas(): atlaisvinama atmintis.

Norint paleisti programą reikia sekti šiuos nurodymus: https://code.visualstudio.com/docs/cpp/config-mingw.
Tada, atsidarius projektą aplanke paleisti jį terminale naudojant komandą g++ v_pradine.cpp -o v_pradine.exe ir tada ./v_pradine.
