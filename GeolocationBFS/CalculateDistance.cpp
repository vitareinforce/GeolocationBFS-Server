#include "CalculateDistance.h" //header bwt definisi dan abstraksi method dan variabel dari class CalculateDistance.
#include "GeoDataSource.hpp" //header bwt definisi dan abstraksi method dan variabel dari class GeoDataSource buat Hitung Jarak.

using namespace std; //namespace std buat cout << cin << dsb.

GeoDataSource gds; //Load Class di Lib GeoDataSource buat Hitung Jarak dan inisiasi objek gds untuk class GeoDataSource.

double CalculateDistance::provinceDistance(double lon, double lat, int log) { //hitung jarak provinsi dengan input longitude, latitude dan log 1 atau 0 (untuk keperluan debug)
	int i = 0; //index bwt looping.
	csv::Parser provinceData = csv::Parser("data/provinsi.csv"); //load csv data provinsi.
	double init_provinceLongitude = stod(provinceData[0]["longitude"]); //ambil sample data longitude dari csv.
	double init_provinceLatitude = stod(provinceData[0]["latitude"]); //ambil sample data latitude dari csv.
	double jarak = gds.distance(lat, lon, init_provinceLatitude, init_provinceLongitude, 'M'); //hitung sample jarak dari latitude longitude dari input data dan data sample latitude longitude.
	//mulai pencarian BFS
	while(i < provinceData.rowCount()) { //looping untuk pencarian data berdasarkan jumlah data yang ada.
		double provinceLongitude = stod(provinceData[i]["longitude"]); //dapatkan data longitude.
		double provinceLatitude = stod(provinceData[i]["latitude"]); //dapatkan data latitude.
		double tmpJarak = gds.distance(lat, lon, provinceLatitude, provinceLongitude, 'M'); //hitung temporary jarak berdasarkan latitude longitude dari input dan dari data csv.
		if(log == 1) { //cek log.
			cout << "Jarak provinsi (before)  : "; //cetak "Jarak provinsi (before)  : "
			cout << jarak; // cetak jarak yang didapat.
			cout << "<br />"; //cetak new line / enter pada html.
			cout << "<br />"; //cetak new line / enter pada html.
		}
		if(jarak >= tmpJarak) { //bandingkan jarak dan temporary jarak, jika temporary jarak lebih pendek dari jarak maka ambil.
			jarak = tmpJarak; //jadikan temporary jarak sebagai jarak yang baru
			provinceCode = stoi(provinceData[i]["id_province"]); //dapatkan id provinsi.
		}
		if(log == 1) { //cek log.
			cout << provinceData[i]["province_name"]; //cetak nama provinsi yang didapat
			cout << "<br />"; //cetak new line / enter pada html.
			cout << "tmpJarak : "; //cetak "tmpJarak".
			cout << tmpJarak; //cetak jarak temporary yang didapat.
			cout << "<br />"; //cetak new line / enter pada html.
			cout << "Jarak provinsi  : "; //cetak "Jarak provinsi".
			cout << jarak; //cetak jarak yang didapat.
			cout << "<br />"; //cetak new line / enter pada html.
		}
		i++; //iterasi
	}
	if(log == 1) {//cek log.
		cout << "final Jarak provinsi : "; //cetak "final Jarak provinsi".
		cout << jarak; //cetak jarak yang didapat
		cout << "<br />"; //cetak new line / enter pada html.
		cout << "<br />"; //cetak new line / enter pada html.
	}
	return jarak; //return jarak yang didapat
}

double CalculateDistance::cityregDistance(double lon, double lat, int log) { //hitung jarak kota / kabupaten dengan input longitude, latitude dan log 1 atau 0 (untuk keperluan debug)
	int i = 0; //index bwt looping.
	csv::Parser cityregData = csv::Parser("data/kota.csv"); //load csv data kota.
	double init_cityregLongitude = stod(cityregData[0]["longitude"]);//ambil sample data longitude dari csv.
	double init_cityregLatitude = stod(cityregData[0]["latitude"]);//ambil sample data latitude dari csv.
	double jarak = gds.distance(lat, lon, init_cityregLatitude, init_cityregLongitude, 'M'); //hitung jarak dengan latitude longitude yang diinput dan sample data.

	while(i < cityregData.rowCount()) { //mulai looping mencari jarak.
		double cityregLongitude = stod(cityregData[i]["longitude"]); //ambil data longitude dari csv.
		double cityregLatitude = stod(cityregData[i]["latitude"]); //ambil data latitude dari csv.
		double tmpJarak = gds.distance(lat, lon, cityregLatitude, cityregLongitude, 'M'); //hitung temporary jarak dengan latitude longitude yang diinput dan data dari csv.
		
		int id_province = stoi(cityregData[i]["id_province"]); //ambil data id provinsi dari csv.
		if(log == 1) { //cek log.
			cout << "id provinsi dr sebelumnya : "; //cetak "id provinsi dr sebelumnya : ".
			cout << provinceCode; //cetak kode provinsi yang didapat dari hasil perhitungan sebelumnya.
			cout << "<br />"; //cetak new line / enter pada html.
			cout << "id provinsi yg didapet : "; //cetak "id provinsi yg didapet : ".
			cout << id_province; //cetak id provinsi yang didapat.
			cout << "<br />"; //cetak new line / enter pada html.
		}
		if(provinceCode == id_province) { //cek kode provinsi yang didapat sebelumnya dengan id provinsi yang didapat dari csv.
			if(log == 1) { //cek log.
				cout << "Jarak Kota (before) : "; //cetak "Jarak Kota (before) : ".
				cout << jarak; //cetak jarak yang didapat.
				cout << "<br />"; //cetak new line / enter pada html.
			}
			if(jarak >= tmpJarak) { //bandingkan jarak dan temporary jarak, jika temporary jarak lebih pendek dari jarak maka ambil.
				jarak = tmpJarak; //jadikan temporary jarak sebagai jarak yang baru.
				cityregCode = stoi(cityregData[i]["id_cityreg"]); //ambil id cityreg dari kota yang didapat pada index ini.
			}
			if(log == 1) { //cek log.
				cout << cityregData[i]["cityreg_name"]; //cetak nama kota.
				cout << "<br />"; //cetak new line / enter pada html.
				cout << "tmpJarak : "; //cetak "tmpJarak : ".
				cout << tmpJarak; //cetak temporary jarak yang didapat.
				cout << "<br />"; //cetak new line / enter pada html.
				cout << "Jarak Kota : "; //cetak "Jarak Kota : ".
				cout << jarak;// cetak jarak yang didapat.
				cout << "<br />"; //cetak new line / enter pada html.
			}
		}
		i++; //iterasi.
	}
	if(log == 1) { //cek log.
		cout << "final Jarak Kota  : "; //cetak "final Jarak Kota".
		cout << jarak; //cetak jarak yang didapat.
		cout << "<br />"; //cetak new line / enter pada html.
		cout << "<br />"; //cetak new line / enter pada html.
	}
	return jarak; //return jarak yang didapat.
}

double CalculateDistance::districtDistance(double lon, double lat, int log) { //hitung jarak kecamatan dengan input longitude, latitude dan log 1 atau 0 (untuk keperluan debug)
	int i = 0; //index bwt looping.
	csv::Parser districtData = csv::Parser("data/kecamatan.csv");  //load csv data kecamatan.
	double init_districtLongitude = stod(districtData[0]["longitude"]);//ambil sample data longitude dari csv.
	double init_districtLatitude = stod(districtData[0]["latitude"]);//ambil sample data latitude dari csv.
	double jarak = gds.distance(lat, lon, init_districtLatitude, init_districtLongitude, 'M');  //hitung jarak dengan latitude longitude yang diinput dan sample data.

	while(i < districtData.rowCount()) { //mulai looping mencari jarak.
		double districtLongitude = stod(districtData[i]["longitude"]);//ambil data longitude dari csv.
		double districtLatitude = stod(districtData[i]["latitude"]);//ambil data latitude dari csv.
		double tmpJarak = gds.distance(lat, lon, districtLatitude, districtLongitude, 'M');  //hitung temporary jarak dengan latitude longitude yang diinput dan data dari csv.
		
		int id_cityreg = stoi(districtData[i]["id_cityreg"]); //ambil data id cityreg dari csv.
		if(log == 1) { //cek log.
			cout << "id kota dr sebelumnya : "; //cetak "id kota dr sebelumnya : ".
			cout << cityregCode; //cetak id kota yang didapat dari hasil perhitungan sebelumnya.
			cout << "<br />"; //cetak new line / enter pada html.
			cout << "id kota yg didapet : "; //cetak "id kota yg didapet : ".
			cout << id_cityreg; //cetak id kota yang didapat dari csv.
			cout << "<br />"; //cetak new line / enter pada html.
		}
		if(cityregCode == id_cityreg) { //cek id kota yang didapat sebelumnya dengan id kota yang didapat pada csv.
			if(log == 1) { //cek log.
				cout << "Jarak Kecamatan (before) : "; //cetak "Jarak Kecamatan (before) : ".
				cout << jarak; //cetak jarak yang didapat
				cout << "<br />"; //cetak new line / enter pada html.
			}
			if(jarak >= tmpJarak) { //bandingkan jarak dan temporary jarak, jika temporary jarak lebih pendek dari jarak maka ambil.
				jarak = tmpJarak; //jadikan temporary jarak sebagai jarak yang baru.
				districtCode = stoi(districtData[i]["id_district"]); //ambil id kecamatan.
			}
			if(log == 1) { //cek log.
				cout << districtData[i]["district_name"];
				cout << "<br />"; //cetak new line / enter pada html.
				cout << "tmpJarak : "; //cetak "tmpJarak : ".
				cout << tmpJarak; //cetak temporary jarak yang didapat.
				cout << "<br />"; //cetak new line / enter pada html.
				cout << "Jarak Kecamatan : "; //cetak "Jarak Kecamatan : ".
				cout << jarak; //cetak jarak yang didapat.
				cout << "<br />"; //cetak new line / enter pada html.
			}
		}
		i++; //iterasi
	}
	if(log == 1) { //cek log.
		cout << "final Jarak Kecamatan  : "; //cetak "final Jarak Kecamatan  : ".
		cout << jarak; //cetak jarak yang didapat.
		cout << "<br />"; //cetak new line / enter pada html.
		cout << "<br />"; //cetak new line / enter pada html.
		cout << "<br />"; //cetak new line / enter pada html.
	}
	return jarak; //return jarak.
}

string CalculateDistance::getProvinceName() {
	int i = 0; //index looping.
	csv::Parser provinceData = csv::Parser("data/provinsi.csv"); //load data provinsi dari csv.
	while(i < provinceData.rowCount()) { //looping data
		int id_province = stoi(provinceData[i]["id_province"]); //ambil id provinsi.
		if(provinceCode == id_province) {//cek id provinsi yang didapat dari hasil perhitungan dengan id provinsi yang didapat dari csv.
			return provinceData[i]["province_name"]; //return nama provinsi yang didapat.
			break; //berhenti
		}
		i++; //iterasi.
	}
}

string CalculateDistance::getCityregName() {
	int i = 0; //index looping.
	csv::Parser cityregData = csv::Parser("data/kota.csv"); //load data kota dari csv.
	while(i < cityregData.rowCount()) { //looping data
		int id_cityreg = stoi(cityregData[i]["id_cityreg"]); //ambil id kota.
		if(cityregCode == id_cityreg) {//cek id kota yang didapat dari hasil perhitungan dengan id kota yang didapat dari csv.
			return cityregData[i]["cityreg_name"]; //return nama kota yang didapat.
			break; //berhenti.
		}
		i++; //iterasi.
	}
}

string CalculateDistance::getDistrictName() {
	int i = 0;//index looping.
	csv::Parser districtData = csv::Parser("data/kecamatan.csv");//load data kota dari csv.
	while(i < districtData.rowCount()) {//looping data
		int id_district = stoi(districtData[i]["id_district"]);//ambil id kecamatan.
		if(districtCode == id_district) {//cek id kecamatan yang didapat dari hasil perhitungan dengan id kecamatan yang didapat dari csv.
			return districtData[i]["district_name"];//return nama kota yang didapat.
			break; //berhenti.
		}
		i++; //iterasi.
	}
}