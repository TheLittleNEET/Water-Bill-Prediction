#ifndef MODEL_REGRESI_H
#define MODEL_REGRESI_H

/* * Fungsi otomatis hasil konversi dari Python (m2cgen)
 * * CARA PENGGUNAAN DI ARDUINO IDE:
 * double data_input[5] = {Musim, Jml_Anggota, Jml_Keran, Ada_Taman, Ada_Toko};
 * double prediksi = score(data_input);
 * * Urutan indeks array input wajib sama:
 * input[0] = Musim (0 = Hujan, 1 = Kemarau)
 * input[1] = Jml_Anggota
 * input[2] = Jml_Keran
 * input[3] = Ada_Taman (0 = Tidak, 1 = Ya)
 * input[4] = Ada_Toko  (0 = Tidak, 1 = Ya)
 */

double score(double * input) {
    return (((((-0.6636943312852885) + ((input[0]) * (3.3511484374986003))) + ((input[1]) * (5.286065980740789))) + ((input[2]) * (0.22554283636722117))) + ((input[3]) * (5.819589394265636))) + ((input[4]) * (10.588726819790468));
}


#endif // MODEL_REGRESI_H
