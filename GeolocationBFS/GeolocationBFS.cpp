// GeolocationBFS.cpp : Defines the entry point for the console application.
//

#include <iostream> //standar C++ library untuk input output stream

#include "CalculateDistance.h" //header bwt definisi dan abstraksi method dan variabel dari class CalculateDistance.

CalculateDistance cdl; //Load Class CalculateDistance buat Algoritma Breadth-first Search, Hitung Jarak dan inisiasi objek cdl untuk class CalculateDistance.

void main() //C dan C++ main method. method yang paling pertama dieksekusi oleh C dan C++ .
{
	double lon; //variable penampung input value dari Longitude (Garis Bujur).
	double lat; //variable penampung input value dari Latitude (Garis Lintang).
	int showLog; //variable penampung input value untuk menampilkan log (1) atau tidak menampilkan log (0).
	char *input; //variable penampung input yang didapat dari URL pada browser saat eksekusi aplikasi ini via CGI.
	string final_provinsi; //variable penampung untuk hasil akhir provinsi yang didapat dari pencarian.
	string final_kota; //variable penampung untuk hasil akhir kota / kabupaten yang didapat dari pencarian.
	string final_kecamatan; //variable penampung untuk hasil akhir kecamatan yang didapat dari pencarian.

	input = getenv("QUERY_STRING"); //mendapatkan value dari URL pada browser saat eksekusi aplikasi ini via CGI.
	if(input==NULL) { //cek value dari URL pada browser bila kosong.
		cout << "Content-Type: text/html" <<endl << endl; //cetak header pada browser yang menunjukan halaman yang di load dalam format HTML.
		cout << "Input Kosong"; //cetak peringatan input kosong.
	} else if(sscanf (input,"lon=%lf & lat=%lf & log=%i",&lon,&lat,&showLog)) { //scan value dari variable input dan mengambil nilai latitude, longitude, dan log sesuai format yang telah ditentukan yaitu longitude dan latitude dalam bentuk double dan log dalam bentuk integer.
		if(showLog == 1) { //pengecekan variable show log untuk memunculkan log atau tidak.
			cout << "Content-Type: text/html" <<endl << endl; //cetak header pada browser yang menunjukan halaman yang di load dalam format HTML.
			cout << "Input Longitude: "; //cetak "Input Longitude"
			cout << lon; //cetak value longitude dari hasil input.
			cout << "<br />"; //cetak new line / enter pada html.
			cout << "Input Latitude: ";  //cetak "Input Latitude"
			cout << lat; //cetak value latitude dari hasil input. 
			cout << "<br />"; //cetak new line / enter pada html.
		}
		double jarakProvinsi = cdl.provinceDistance(lon,lat,showLog); //hitung jarak provinsi dengan input longitude, latitude dan showLog untuk menampilkan log atau tidak.
		string namaProvinsi = cdl.getProvinceName(); //mendapatkan nama provinsi dari hasil perhitungan jarak provinsi, fungsi ini tidak akan berfungsi apabila tidak dilakukan perhitungan terlebih dahulu.
		if(showLog == 1) { //pengecekan variable show log untuk memunculkan log atau tidak.
			cout << "<br />"; //cetak new line / enter pada html.
		}
		final_provinsi = namaProvinsi; //simpan hasil final nama provinsi dari hasil perhitungan jarak.
		if(showLog == 1) { //pengecekan variable show log untuk memunculkan log atau tidak.
			cout << namaProvinsi; //cetak nama provinsi yang sudah didapat.
			cout << "<br />"; //cetak new line / enter pada html.
			cout << "Jarak ke Pusat Provinsi : "; //cetak "Jarak Pusat Ke Provinsi".
			cout << jarakProvinsi << " Meter"; //cetak jarak provinsi yang didapat dari hasil perhitungan.
			cout << "<br />"; //cetak new line / enter pada html.
		}
		double jarakKota = cdl.cityregDistance(lon,lat,showLog); //hitung jarak kota / kabupaten dengan input longitude, latitude dan showLog untuk menampilkan log atau tidak.
		string namaKota = cdl.getCityregName(); //mendapatkan nama kota / kabupaten dari hasil perhitungan jarak kota / kabupagen, fungsi ini tidak akan berfungsi apabila tidak dilakukan perhitungan terlebih dahulu.
		if(showLog == 1) { //pengecekan variable show log untuk memunculkan log atau tidak.
			cout << "<br />"; //cetak new line / enter pada html.
		}
		final_kota = namaKota; //simpan hasil final nama kota / kabupaten dari hasil perhitungan jarak.
		if(showLog == 1) { //pengecekan variable show log untuk memunculkan log atau tidak.
			cout << namaKota; //cetak nama kota / kabupagen yang sudah didapat.
			cout << "<br />"; //cetak new line / enter pada html.
			cout << "Jarak ke Pusat Kota: "; //cetak "Jarak ke Pusat Kota"
			cout << jarakKota << " Meter"; //cetak jarak kota / kabupaten yang didapat dari hasil perhitungan.
			cout << "<br />"; //cetak new line / enter pada html.
		}
		double jarakKecamatan = cdl.districtDistance(lon,lat,showLog); //hitung jarak kecamatan dengan input longitude, latitude dan showLog untuk menampilkan log atau tidak.
		string namaKecamatan = cdl.getDistrictName(); //mendapatkan nama kecamatan dari hasil perhitungan jarak kecamatan, fungsi ini tidak akan berfungsi apabila tidak dilakukan perhitungan terlebih dahulu.
		if(showLog == 1) { //pengecekan variable show log untuk memunculkan log atau tidak.
			cout << "<br />"; //cetak new line / enter pada html.
		}
		final_kecamatan = namaKecamatan;
		if(showLog == 1) { //pengecekan variable show log untuk memunculkan log atau tidak.
			cout << namaKecamatan; //cetak nama kecamatan yang sudah didapat.
			cout << "<br />"; //cetak new line / enter pada html.
			cout << "Jarak ke Pusat Kecamatan: "; //cetak "Jarak ke Pusat Kecamatan".
			cout << jarakKecamatan << " Meter"; //cetak jarak kecamatan yang didapat dari hasil perhitungan.
			cout << "<br />"; //cetak new line / enter pada html.
		}
		if(showLog == 0) { //pengecekan variable show log untuk memunculkan hasil akhir.
			cout << "Content-Type: text/html" <<endl <<endl; //cetak header pada browser yang menunjukan halaman yang di load dalam format HTML.
			cout << "provinsi:" << final_provinsi << "<br />"; //cetak hasil akhir provinsi yang sudah didapat.
			cout << "kota:" << final_kota << "<br />"; //cetak hasil akhir provinsi yang sudah didapat.
			cout << "kecamatan:" << final_kecamatan << "<br />"; //cetak hasil akhir provinsi yang sudah didapat.
		}
	}
}

