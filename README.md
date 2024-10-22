<B> <h1> 1-OJI UŽDUOTIS </B> </h1>

Ši programa (suprogramuota C++ programavimo kalba) yra skirta apskaičiuoti studentų pažymius, remiantis jų namų darbų ir egzamino rezultatais.

<details>
   <summary> <B> <h2> Programos veikimo principas:</B> </h2>
</summary>
1. Programa leidžia vartotojui pasirinkti, ar duomenys bus suvedami ranka, sugeneruojami atsitiktinai ar nuskaitomi iš failo. Duomenys - vardas, pavardė, namų darbų pažymys, egzamino pažymys.
   
   a) pasirinkus duomenis suvesti ranka prašoma nurodyti studentų ir namų darbų skaičių, tada vartotojas viską suveda pats;
   
   b) pasirinkus duomenis generuoti atsitiktinai, prašoma nurodyti studentų ir namų darbų skaičių, vartotojas suveda tik vardus ir pavardes, pažymiai             generuojami atsitiktinai;
   
   c) pasirinkus duomenis nuskaityti iš failo paprašoma suvesti failo pavadinimą;
3. Paklausiama, ar galutinio pažymio skaičiavimui norima naudoti namų darbų vidurkį ar medianą, tada atsižvelgiant į pasirinkimą apskaičiuojamas galutinis pažymis remiantis formule - 0.4×nd+0.6×egzaminas.
4. Paklausiama, ar vartotojas nori surūšiuoti studentų duomenis pagal vardą arba pavardę.
5. Duomenys yra išvedami, paklausus vartotojo, kaip juos nori išvesti - spausdinti terminale, įvesti į vieną failą ar suskirtyti studentus į "šaunuolius" ir "nevykelius" ir išvesti juos į du atskirus failus.
6. Išvedus duomenis programos veikimas baigiamas.
</details>

<details>
<summary> <B> <h2> Funkcijos:</B> </h2>
</summary>
   
   1. ndVidurkis(): apskaičiuoja namų darbų pažymių vidurkį.
2. ndMediana(): apskaičiuoja namų darbų pažymių medianą.
3. galutinis(): apskaičiuoja galutinį pažymį.
4. ivestiDuomenisRanka(): leidžia įvesti duomenis rankiniu būdu.
5. atsitiktiniaiPazymiai(): sugeneruoja atsitiktinius pažymius.
6. nuskaitytiFaila(): nuskaito duomenis iš failo.
7. spausdinti(): atspausdina studentų duomenis lentelėje (vardas, pavarde, galutinis).
8. isvestiFaila(): nuskaityti/suvesti duomenys išvedami į tekstinį failą.
9. generuotiFailus(): generuoja failus su atsitikitiniais duomenimis
10. paskirtytiStud(): isskirsto studentus pagal ju galutinį pažymį.
11. valymas(): atlaisvinama atmintis.
</details>

<details> <summary> <b> <h2> Testavimas: </b> </h4> </summary>

*Testavimo sistemos parametrai:*

CPU: 11th Gen Intel(R) Core(TM) i5-11300H

RAM: 8 GB

SSD: 475 GB

**Buvo atlikta programos spartos analizė penkiems skirtingiems sugeneruotiems failams (1000, 10000, 100000, 1000000, 10000000 įrašų):**
Visiems testavimams buvo pasirinktas galutinio pažymio skaičiavimas pagal *vidurkį* ir studentų rūšiavimas pagal *vardą*.
<details>
   <summary>
      <h3>
         Failų generavimo spartos analizė:
      </h3>
   </summary>
   
   ![image](https://github.com/user-attachments/assets/9b2335aa-042f-4e74-b613-a236f5905c81)
   ![image](https://github.com/user-attachments/assets/0d33a0b8-eab8-456f-b48b-06ab340990c4)
   ![image](https://github.com/user-attachments/assets/4fc01a72-447a-45f0-837c-71a21c1c6dce)
   ![image](https://github.com/user-attachments/assets/5525eee9-ce1e-417d-aeca-c6e2083b8a2a)
   ![image](https://github.com/user-attachments/assets/4addd01f-46b5-4600-9175-55a7e5564142)
</details>

<details>
   <summary>
      <h3>
         Failų testavimas (vektoriaus tipo konteinerio): 
      </h3>
   </summary>   
   
1000 įrašų spartos analizė:

![image](https://github.com/user-attachments/assets/fa562570-3a6a-4dd8-aba3-fe602a704517)

10000 įrašų spartos analizė:

![image](https://github.com/user-attachments/assets/6d633d3f-ecc5-49d8-87ef-6751f9e6764b)

100000 įrašų spartos analizė:

![image](https://github.com/user-attachments/assets/03ff09b3-f831-4c04-a3ed-b34af6a21192)

1000000 įrašų spartos analizė:

![image](https://github.com/user-attachments/assets/d17c1d3a-8584-4934-8229-dc4a25df9cf0)

10000000 įrašų spartos analizė:

![image](https://github.com/user-attachments/assets/0bed1f3e-5be8-4222-9248-da39a6b831e6)

   </summary>
   
</details>

</details>

Norint paleisti programą reikia sekti šiuos nurodymus: https://code.visualstudio.com/docs/cpp/config-mingw.
Tada, atsidarius projektą aplanke paleisti jį terminale naudojant komandą g++ header.h Stud.cpp Stud.h main.cpp -o programa.exe ir tada ./programa.
