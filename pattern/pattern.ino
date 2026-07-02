#include <Arduino.h>
#include "model_regresi.h"

void setup() {
  Serial.begin(115200);
  delay(2000);
  
  Serial.println("=========================================");
  Serial.println("   SISTEM PREDIKSI PENGGUNAAN AIR IoT    ");
  Serial.println("         EDGE AI / TINYML ESP32          ");
  Serial.println("=========================================");

  // --- SIMULASI KASUS DATA INPUT (Wajib Berisi 5 Fitur) ---
  // Urutan indeks array input harus sama persis dengan di Python:
  // index 0 = Musim (0 = Hujan, 1 = Kemarau)
  // index 1 = Jml_Anggota
  // index 2 = Jml_Keran
  // index 3 = Ada_Taman (0 = Tidak, 1 = Ya)
  // index 4 = Ada_Toko  (0 = Tidak, 1 = Ya)
  
  // Contoh Rumah A: Musim Kemarau, 4 orang, 5 keran, punya taman, tapi gak buka toko
  double rumah_A[5] = {1.0, 4.0, 5.0, 1.0, 0.0};
  
  // Contoh Rumah B: Musim Hujan, 2 orang, 3 keran, gak punya taman, gak punya toko
  double rumah_B[5] = {0.0, 2.0, 3.0, 0.0, 0.0};

  // --- DATA TARIF STATIS (Business Logic) ---
  double tarif_per_m3 = 4500.0;
  double beban_tetap = 20000.0;

  // Fungsi score() akan mengembalikan estimasi dalam satuan m3
  double prediksi_volume_A = score(rumah_A);
  double prediksi_volume_B = score(rumah_B);

  // --- PROSES PERHITUNGAN BIAYA (Kalkulator Finansial) ---
  double tagihan_A = (prediksi_volume_A * tarif_per_m3) + beban_tetap;
  double tagihan_B = (prediksi_volume_B * tarif_per_m3) + beban_tetap;

  // --- TAMPILKAN HASIL ---
  Serial.println("\n[Hasil Prediksi Rumah A]");
  Serial.println("- Profil  : Kemarau, 4 Orang, Ada Taman");
  Serial.print("- Estimasi Volume Air : ");
  Serial.print(prediksi_volume_A, 2);
  Serial.println(" m3");
  Serial.print("Estimasi Tagihan   : Rp ");
  Serial.println(tagihan_A, 2);

  Serial.println("\n[Hasil Prediksi Rumah B]");
  Serial.println("- Profil  : Hujan, 2 Orang, Rumah Standar");
  Serial.print("- Estimasi Volume Air : ");
  Serial.print(prediksi_volume_B, 2);
  Serial.println(" m3");
  Serial.print("Estimasi Tagihan   : Rp ");
  Serial.println(tagihan_B, 2);
  
  Serial.println("\n=========================================");
}

void loop() {
}