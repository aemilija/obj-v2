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

<details> <summary> <b> <h2> Spartos analizė: </b> </h4> </summary>

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

![image](https://github.com/user-attachments/assets/2f8186ad-2641-4633-b1ea-7f152ad4a328)

</details>

<details>
   <summary>
      <h3>
         Failų testavimas (list tipo konteinerio):
      </h3>
   </summary>
   
   1000 įrašų spartos analizė:
   
   ![image](https://github.com/user-attachments/assets/111c876a-6bf1-4f39-af69-4eba2bc4a008)

   10000 įrašų spartos analizė:

   ![image](https://github.com/user-attachments/assets/d49d2f4b-659a-4aa5-8a3f-2ebd825fdf35)

   100000 įrašų spartos analizė:

   ![image](https://github.com/user-attachments/assets/a8a206da-dc9a-40ea-ac3d-9df25911d755)

   1000000 įrašų spartos analizė:

   ![image](https://github.com/user-attachments/assets/d876eccf-189a-4332-a265-8672e54939ca)

   10000000 įrašų spartos analizė:

   ![image](https://github.com/user-attachments/assets/e03b8bcb-b3bf-4318-a76c-d50ddd5e4483)

</details>

<details>
   <summary>
      <h3>
         Konteinerių palyginimas:
      </h3>
   </summary>
   
- 1000 irašų vector ir list spartos palyginimas:
   
| Operacija                          | Vector (s)  | List (s)  |
|------------------------------------|-------------|-----------|
| Nuskaitymas                        | 0,00342     | 0,01123   |
| Rūšiavimas                         | 0,00139     | 0,00069   |
| Paskirstymas                       | 0,00052     | 0,00046   |
| Išvedimas (šaunuoliai)             | 0,01230     | 0,00645   |
| Išvedimas (nevykėliai)             | 0,00550     | 0,00876   |

- 10000 irašų vector ir list spartos palyginimas:

| Operacija                          | Vector (s)  | List (s)  |
|------------------------------------|-------------|-----------|
| Nuskaitymas                        | 0,02844     | 0,03768   |
| Rūšiavimas                         | 0,00949     | 0,00313   |
| Paskirstymas                       | 0,00409     | 0,00341   |
| Išvedimas (šaunuoliai)             | 0,07898     | 0,08625   |
| Išvedimas (nevykėliai)             | 0,03133     | 0,03919   |

- 100000 irašų vector ir list spartos palyginimas:

| Operacija                          | Vector (s)  | List (s)  |
|------------------------------------|-------------|-----------|
| Nuskaitymas                        | 0,26184     | 0,26287   |
| Rūšiavimas                         | 0,11514     | 0,05506   |
| Paskirstymas                       | 0,04328     | 0,04822   |
| Išvedimas (šaunuoliai)             | 0,65213     | 0,66420   |
| Išvedimas (nevykėliai)             | 0,24594     | 0,28796   |

- 1000000 irašų vector ir list spartos palyginimas:

| Operacija                          | Vector (s)  | List (s)  |
|------------------------------------|-------------|-----------|
| Nuskaitymas                        | 2,45252     | 2,62928   |
| Rūšiavimas                         | 1,41259     | 0,78329   |
| Paskirstymas                       | 0,38858     | 0,44316   |
| Išvedimas (šaunuoliai)             | 5,50744     | 7,33919   |
| Išvedimas (nevykėliai)             | 2,63698     | 3,08263   |

- 10000000 irašų vector ir list spartos palyginimas:

| Operacija                          | Vector (s)  | List (s)  |
|------------------------------------|-------------|-----------|
| Nuskaitymas                        | 29,48737     | 25,16040   |
| Rūšiavimas                         | 17,41753     | 12,86151   |
| Paskirstymas                       | 7,73298     | 7,09569   |
| Išvedimas (šaunuoliai)             | 58,75183     | 56,86274   |
| Išvedimas (nevykėliai)             | 41,67963     | 39,59465   |


</details>
</details>

</details>

<details>
   <summary>
      <h2>
         <b>
            Studentų rūšiavimo optimizavimas:
         </b>
      </h2>
   </summary>

   ***1 strategija:***
   Bendro studentai konteinerio skaidymas į du naujus to paties tipo konteinerius: "šaunuolių" ir "nevykėlių". Studentas yra dviejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (šaunuoliai arba nevykėliai). 

| Įrašų skaičius | Vector (s) | List (s) |
|----------------|------------|----------|
| 1000           | 0,00052    | 0,00046  |
| 10000          | 0,00409    | 0,00313  |
| 100000         | 0,04328    | 0,04822  |
| 1000000        | 0,38858    | 0,44316  |
| 10000000       | 7,73298    | 7,09569  |

   ***2 strategija:***
   Bendro studentų konteinerio skaidymas panaudojant tik vieną naują konteinerį: "nevykėliai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "nevykėlių" konteinerį ir ištrinti iš bendro studentai konteinerio. Studentai konteineryje liks tik šaunuoliai.

| Įrašų skaičius | Vector (s) | List (s) |
|----------------|------------|----------|
| 1000           | 0,01785    | 0,00070  |
| 10000          | 1,46294    | 0,00761  |
| 100000         | 138,39729    | 0,06321  |
| 1000000        | -    | 0,45251  |
| 10000000       | -    | 9,35102  |

   ***3 strategija:***
   Bendro studentų konteinerio skaidymas panaudojant 1-ą strategiją, įtraukiant į ją "efektyvius" darbo su konteineriais metodus.

   | Įrašų skaičius | Vector (s) | List (s) |
|----------------|------------|------------|
| 1000           | 0,00033    | 0,00052    |
| 10000          | 0,00460    | 0,00452    |
| 100000         | 0,03763    | 0,08442    |
| 1000000        | 0,43216    | 0,86780    |
| 10000000       | 6,91909    | 11,37723   |


</details>

<details>
   <summary>
      <h2>
         <b>
            Struct ir Class palyginimas
         </b>
      </h2>
   </summary>

   <details>
      <summary>
         <h3>
            <b>
               Programos spartos palygimas:
            </b>
         </h3>
      </summary>
      
- 100000 irašų struct ir class spartos palyginimas:

| Operacija                          | Struct (s)  | Class (s)  |
|------------------------------------|-------------|-----------|
| Nuskaitymas                        | 0,26569     | 1,53554   |
| Rūšiavimas                         | 0,12325     | 0,24837   |
| Paskirstymas                       | 0,04256     | 0,07276   |
| Išvedimas (šaunuoliai)             | 0,78536     | 0,83173   |
| Išvedimas (nevykėliai)             | 0,36876     | 0,36213   |

- 1000000 irašų struct ir class spartos palyginimas:

| Operacija                          | Vector (s)  | List (s)  |
|------------------------------------|-------------|-----------|
| Nuskaitymas                        | 2,72176     | 3,28820   |
| Rūšiavimas                         | 1,91250     | 3,03190   |
| Paskirstymas                       | 0,49343     | 0,67395   |
| Išvedimas (šaunuoliai)             | 8,77235     | 8,74437   |
| Išvedimas (nevykėliai)             | 6,48919     | 5,41000   |

      
   </details>

<details>
   <summary>
      <h3>
         <b>
            Kompiliatoriaus optimizavimo lygio analizė:
         </b>
      </h3>
   </summary>
         
   **Kompiliavimo greitis (s):**
         
| Optimizacijos lygis | Struct | Class |
|--------------------|--------|--------|
| *-o1*            | 4,58473 | 5,17492 |
| *-o2*            | 5,63571 | 5,53093 |
| *-o3*            | 5,43420 | 6,16581 |

   **Failo dydis (KB):**
   
   | Optimizacijos lygis | Struct | Class |
|--------------------|--------|-------|
| *-o1*            |    223  |  243  |
| *-o2*            |    212  |  233  |
| *-o3*            |    225  |  264  |

         
</details> 
</details>


<details>
   <summary>
      <h2>
         <b>
            Naudojimosi instrukcija:
         </b>
      </h2>
   </summary>

***Naudojant kompiliarorių:***
1. Sekti nurodymus https://code.visualstudio.com/docs/cpp/config-mingw t. y. parsisiųsti VSCode ir reikalingą kompiliarių.
2. Parsisiuntus projekto kodą ir jį atsidarius VSCode terminale paleisti komandą g++ header.h Stud.cpp Stud.h main.cpp -o programa.exe (čia sukompiliuojama), o norint paleisti naudoti komandą ./programa

***Naudojant CMake:***
1. Parsisiųsti CMake, sekant nurodymus https://cmake.org/download/ ir įsidiegti.
2. Terminale paeiliuj paleisti šias komandas (arba aplanko, kurį norite naudoti viduje paleisti "run.bat" failą, tada komandų terminale leisti nereikės):
      * cmake CMakeLists.txt
      * cmake --build .
      * cmake --install .
      * cd Debug\
3. Aplanke, turėjo atsirasti dar vienas aplankas, pavadinimu "Debug", paspaudus ant jo rasite programą - "studentai", paspaudus ant jos galėsite naudotis programa.
</details>
