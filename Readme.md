# Langkah-langkah Instalasi C++ di WSL dan Setup di Visual Studio Code

Panduan ini akan membantu Anda menginstal C++ di WSL (Windows Subsystem for Linux) dan menghubungkannya dengan Visual Studio Code (VS Code) untuk mengembangkan dan menjalankan program C++.

## 1. Setup Ubuntu di WSL
Langsung buka WSL Ubuntu dan ikuti langkah-langkah berikut:

1. **Update sistem paket**:
   Setelah login ke terminal Ubuntu, jalankan:
   ```bash
   sudo apt update && sudo apt upgrade
   ```

2. **Instal g++ (C++ Compiler)**:
   Untuk mengembangkan program C++ di WSL, Anda perlu menginstal compiler:
   ```bash
   sudo apt install g++
   ```

3. **Verifikasi Instalasi**:
   Pastikan g++ terinstal dengan benar dengan menjalankan:
   ```bash
   g++ --version
   ```
   Anda harus melihat informasi versi g++ yang terinstal.


## 2. Instalasi Visual Studio Code

1. **Download dan Instal VS Code**:
   Jika Anda belum memiliki Visual Studio Code, unduh dan instal dari situs resmi [Visual Studio Code](https://code.visualstudio.com/).

2. **Instal Extension WSL di VS Code**:
   - Buka Visual Studio Code.
   - Buka **Extensions** dengan menekan `Ctrl + Shift + X`.
   - Cari extension **Remote - WSL** oleh Microsoft.
   - Klik **Install** untuk menginstal extension ini.

3. **Buka VS Code dengan WSL**:
   - Buka terminal WSL, kemudian navigasi ke folder proyek Anda:
      ```bash
      cd /path/to/your/project
      ```
   - Jalankan perintah berikut untuk membuka folder di VS Code:
      ```bash
      code .
      ```
   - VS Code akan terbuka dalam mode WSL.


## 3. Konfigurasi Visual Studio Code untuk C++

1. **Instal Extension C++**:
   - Buka **Extensions** di Visual Studio Code dengan menekan `Ctrl + Shift + X`.
   - Cari extension **C/C++** oleh Microsoft.
   - Klik **Install**.

2. **Instalasi Code Runner (Opsional)**:
   Code Runner memudahkan untuk menjalankan kode dengan cepat di VS Code.
   - Cari **Code Runner** di panel Extensions.
   - Klik **Install** untuk menginstalnya.

3. **Setup Build dan Debug untuk C++**:
   - Buka **Command Palette** dengan menekan `Ctrl + Shift + P`.
   - Ketik **C++**, lalu pilih **C++: Build and debug active file**.
   - Pilih `g++` sebagai compiler saat diminta.


## 4. Menjalankan Program C++

1. Kompilasi Manual melalui Terminal  
   Untuk menjalankan program secara manual melalui terminal, lakukan langkah-langkah berikut:
   - Buka terminal di Visual Studio Code atau WSL.
   - Navigasikan ke direktori proyek Anda jika belum berada di sana:
   ```bash
   cd /path/to/your/project
   ```
   - Masukkan perintah berikut untuk mengompilasi file C++:
   ```bash
   g++ nama_program.cpp -o program
   ```
   - Jalankan program yang telah dikompilasi:
   ```bash
   ./program
   ```
   
2. Menjalankan Program Menggunakan Code Runner:  
   Jika Anda sudah menginstal **Code Runner**, Anda bisa menjalankan file C++ dengan mudah:
   - Buka file `.cpp` yang ingin dijalankan di VS Code.
   - Klik ikon **Run** di pojok kanan atas, atau tekan `Ctrl + Alt + N`.
   - Output akan muncul di bagian terminal VS Code.


## 5. Troubleshooting
Jika Anda mengalami masalah saat menjalankan program C++, berikut beberapa langkah yang dapat membantu:

1. **Periksa Instalasi g++**:
   Pastikan `g++` sudah terinstal dengan benar dengan menjalankan:
   ```bash
   g++ --version
   ```
   Jika tidak melihat informasi versi g++, ulangi proses instalasi `g++` menggunakan perintah:
   ```bash
   sudo apt install g++
   ```

2. **Periksa Path Program**:
   Pastikan Anda berada di direktori yang benar saat menjalankan perintah kompilasi dan eksekusi. Gunakan perintah berikut untuk memverifikasi bahwa file .cpp Anda ada di direktori saat ini:
   ```bash
   ls
   ```

3. **Masalah dengan Build dan Debug di VS Code**:
   Jika terjadi masalah ketika Anda mencoba build atau debug di VS Code, lakukan hal berikut:
   - Pastikan Anda telah memilih C++: **Build and debug active file** melalui **Command Palette** `Ctrl + Shift + P`.
   - Periksa file konfigurasi `tasks.json` dan `launch.json` di dalam folder `.vscode`, dan pastikan konfigurasi sesuai dengan sistem Anda.
   - Jika tetap bermasalah, Anda bisa mencoba menghapus file konfigurasi tersebut dan membuatnya ulang dengan menggunakan **C++: Build and debug active file**.

4. **Error pada Terminal WSL**:
   Jika ada pesan error di terminal saat menjalankan program:
   - **File tidak ditemukan**: Periksa kembali nama file atau path. Pastikan Anda berada di direktori yang benar.
   - **Permission denied**: Jika Anda tidak memiliki izin untuk menjalankan file, berikan izin dengan perintah:
   ```bash
   chmod +x program
   ```

5. **Masalah dengan Code Runner**:
   Jika Anda tidak dapat menjalankan program menggunakan Code Runner:
   - Pastikan Code Runner sudah terinstal dan aktif.
   - Coba restart VS Code setelah instalasi extension.
   - Jika error terus muncul, buka Settings di VS Code, lalu cari "Code Runner" dan pastikan path eksekusi untuk C++ benar.


## 6. Dokumentasi Tambahan

Jika Anda ingin mempelajari lebih lanjut tentang penggunaan C++ di WSL atau bagaimana mengoptimalkan penggunaan VS Code untuk pengembangan, berikut beberapa dokumentasi yang berguna:

1. [Dokumentasi resmi WSL di Microsoft](https://learn.microsoft.com/en-us/windows/wsl)
2. [Dokumentasi g++ - GCC Official](https://gcc.gnu.org/onlinedocs/)
3. [Dokumentasu resmi Visual Studio Code](https://code.visualstudio.com/docs)
4. [Remote Development menggunakan VS Code](https://code.visualstudio.com/docs/remote/remote-overview)

Dengan mengikuti langkah-langkah di atas, Anda seharusnya dapat memulai pengembangan C++ di WSL menggunakan Visual Studio Code dengan lancar. Semoga panduan ini bermanfaat!

---

<h3 align="left">Socials</h3>
<p align="center"> 
  <a href="https://www.github.com/Rafly1818" target="_blank" rel="noreferrer"> 
    <picture> 
      <source media="(prefers-color-scheme: dark)" srcset="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/socials/github-dark.svg" /> 
      <source media="(prefers-color-scheme: light)" srcset="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/socials/github.svg" /> 
      <img src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/socials/github.svg" width="32" height="32" alt="GitHub" /> 
    </picture> 
  </a> 
  <a href="http://www.instagram.com/flyyr_" target="_blank" rel="noreferrer"> 
    <picture> 
      <source media="(prefers-color-scheme: dark)" srcset="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/socials/instagram-dark.svg" /> 
      <source media="(prefers-color-scheme: light)" srcset="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/socials/instagram.svg" /> 
      <img src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/socials/instagram.svg" width="32" height="32" alt="Instagram" /> 
    </picture> 
  </a>
</p>