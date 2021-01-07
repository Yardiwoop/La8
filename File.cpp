#include "stdafx.h"

#include "File.h"

File::File() : name("-"), key(no), size(0) {}
File::File(string n, Key k) : name(n), key(k), size(0) {}
File& operator<<(File& file, const char* s)
{

	if (!file.file.is_open())
	{
		throw 1;
	}

	/*catch (int i)
	{
	Exception ex(i);
	ex.Print();
	}*/
	string str = s;
	file.file << str;
	return file;
}
fstream& operator<<(fstream& out, Student& t) {

	if (!out.is_open())
	{
		throw 1;
	}

	/*catch (int i)
	{
	Exception ex(i);
	ex.Print();
	}*/
	int a = out.tellg();
	string fio = t.get_fio();
	size_t len1 = fio.length() + 1;

	int groups = t.get_groups();
	int point = t.get_point();
	int money = t.get_money();

	string subject = t.get_subject();
	size_t len2 = subject.length() + 1;

	out.write((char*)(&len1), sizeof(len1));
	out.write((char*)(fio.c_str()), len1);

	out.write((char*)(&groups), sizeof(groups));
	out.write((char*)(&point), sizeof(point));

	out.write((char*)(&len2), sizeof(len2));
	out.write((char*)(subject.c_str()), len2);

	out.write((char*)(&money), sizeof(money));

	return out;
}
File& operator<<(File& file, Student& t)
{
	int pos = 0, a = 0, size = 0;

	if (!file.file.is_open())
	{
		cout << "1";
	}

	/*catch (int i)
	{
	Exception ex(i);
	ex.Print();
	}*/
	if (file.key == txt) {
		file.file << t.get_fio() << " " << t.get_groups() << " " << t.get_point() << " "
			<< t.get_subject() << " " << t.get_money() << endl;
	}
	else if (file.key == bin) {
		string fio = t.get_fio();
		size_t len1 = fio.length() + 1;

		int groups = t.get_groups();
		int point = t.get_point();
		int money = t.get_money();

		string subject = t.get_subject();
		size_t len2 = subject.length() + 1;

		file.file.write((char*)(&len1), sizeof(len1));
		file.file.write((char*)(fio.c_str()), len1);

		file.file.write((char*)(&groups), sizeof(groups));
		file.file.write((char*)(&point), sizeof(point));

		file.file.write((char*)(&len2), sizeof(len2));
		file.file.write((char*)(subject.c_str()), len2);
		file.file.write((char*)(&money), sizeof(money));
	}
	return file;
}
ostream& operator<<(ostream& out, File& file)
{
	int a = 0;

	if (!file.file.is_open())
	{
		throw 1;
	}

	/*catch (int i)
	{
	Exception ex(i);
	ex.Print();
	}*/
	if (file.key == txt) {
		string str;
		while (!file.file.eof()) {
			getline(file.file, str);
			a = file.file.tellg();
			cout << str << endl;
		}
	}
	else if (file.key == bin) {
		int i = 0;
		int size = 0, step = 0;
		/*Student tmp;*/
		while (i < file.size) {
			int point;
			int groups;
			int money;

			size_t len;

			file.file.read((char*)(&len), sizeof(len));
			char* f = new char[len];

			file.file.read((char*)(f), len);
			f[len - 1] = '\0';

			file.file.read((char*)(&groups), sizeof(int));
			file.file.read((char*)(&point), sizeof(int));

			file.file.read((char*)(&len), sizeof(len));
			char* s = new char[len];

			file.file.read((char*)(s), len);
			s[len - 1] = '\0';

			file.file.read((char*)(&money), sizeof(int));

			cout << f << " " << groups << " " << point << " " << s << " " << money << endl;

			delete[] f;
			delete[] s;
			i++;

		}
	}
	return out;
}

File::~File() { file.close(); }
void File::open(string mode)
{
	switch (key)
	{
	case txt: {
		if (mode == "r") {
			file.open(name, ios_base::in);   //äëÿ ââîäà
		}
		else if (mode == "add") {
			file.open(name, ios_base::app);  //çàïèñü â êîíåö ôàéëà
		}
		else if (mode == "w") {
			file.open(name, ios_base::out);  //äëÿ âûâîäà
		}
		else if (mode == "wr") {
			file.open(name, ios_base::in | ios_base::out); //äëÿ ââîäà è âûâîäà
		}
		break;
	}
	case bin: {
		if (mode == "r") {
			file.open(name, ios_base::binary | ios_base::in);    //äëÿ ââîäà
		}
		else if (mode == "add") {
			file.open(name, ios_base::binary | ios_base::app);   //çàïèñü â êîíåö ôàéëà
		}
		else if (mode == "w") {
			file.open(name, ios_base::binary | ios_base::out);   //äëÿ âûâîäà
		}
		else if (mode == "wr") {
			file.open(name, ios_base::binary | ios_base::in | ios_base::out);   //äëÿ ââîäà è âûâîäà
		}
		break;
	}

	}
	/*if (!file.is_open())
	{
	throw ;
	}
	*/
}
void File::close()
{
	file.close();
}
void File::begin()
{
	file.seekg(0, ios_base::beg);  //ïåðåìåùåíèå óêàçàòåëÿ ïîçèöèîíèðîâàíèÿ â íà÷àëî ôàéëà
}
void File::set_size(int s) {
	size = s;
}
int File::get_size() {
	return	size;
}
Student File::read()
{
	string str;
	Student t;
	getline(this->file, str, ' ');
	t.set_fio(str);
	getline(this->file, str, ' ');
	t.set_groups(stoi(str));
	getline(this->file, str, ' ');
	t.set_point(stoi(str));
	getline(this->file, str, ' ');
	t.set_subject(str);
	getline(this->file, str);
	t.set_money(stoi(str));
	return t;
}
void File::edit(int line, Student mas[]) {
	this->open("wr");

	int a, b;

	/*try {
	if (!file.is_open())
	{
	throw 1;
	}
	}
	catch (int i)
	{
	Exception ex(i);
	ex.Print();
	return;
	}*/
	Student tmp;
	if (this->key == txt) {
		string str;
		for (int i = 0; i < line - 1; i++)
			getline(this->file, str);
		getline(this->file, str, ' ');
		tmp.set_fio(str);
		getline(this->file, str, ' ');
		tmp.set_groups(stoi(str));
		getline(this->file, str, ' ');
		tmp.set_point(stoi(str));
		getline(this->file, str, ' ');
		tmp.set_subject(str);
		getline(this->file, str);
		tmp.set_money(stoi(str));
	}
	else if (this->key == bin) {
		size_t len;
		for (int i = 0; i < line; i++) {
			this->file.read((char*)(&len), sizeof(len));
			char* n = new char[len];
			string fio;
			string subject;
			int groups = 0, point = 0, money = 0;

			this->file.read((char*)(n), len);
			fio = n;
			fio[len - 1] = '\0';
			this->file.read((char*)(&groups), sizeof(int));
			this->file.read((char*)(&point), sizeof(int));

			this->file.read((char*)(&len), sizeof(len));
			this->file.read((char*)(n), len);
			subject = n;
			subject[len - 1] = '\0';

			this->file.read((char*)(&money), sizeof(int));

			tmp.set_fio(fio);
			tmp.set_groups(groups);
			tmp.set_point(point);
			tmp.set_subject(subject);
			tmp.set_money(money);
			delete[]n;
		}
		a = file.tellg();
	}
}

void File::bouble_sort_fio()
{
	string tmp;
	string s1, s2;
	int pos;
	this->open("wr");
	/*try {
	if (!file.is_open())
	{
	throw 1;
	}
	}
	catch (int i)
	{
	Exception ex(i);
	ex.Print();
	return;
	}*/
	for (int i = 0; i < this->size - 1; i++) {
		for (int j = 0; j < this->size - i - 1; j++)
		{
			this->file.seekg(0, ios_base::beg);
			for (int k = 0; k < j; k++)
				getline(this->file, s1);
			getline(this->file, s1, ' ');
			getline(this->file, s2);
			getline(this->file, s2, ' ');
			if (s1 > s2)
			{
				this->file.seekg(0, ios_base::beg);
				pos = this->file.tellg();
				for (int k = 0; k <= j; k++)
				{
					getline(this->file, s1);
					pos = this->file.tellg();
				}
				tmp = s1;
				getline(this->file, s2);
				this->file.seekg(0, ios_base::beg);
				for (int k = 0; k < j; k++)
				{
					getline(this->file, s1);
				}
				pos = this->file.tellg();
				this->file.seekg(pos, ios_base::beg);
				this->file << s2 << '\n';
				this->file << tmp << '\n';
			}
		}
	}
	this->close();
}
void File::bouble_sort_groups() {
	string tmp;
	string s1, s2;
	int i1, i2;
	int pos;
	this->open("wr");
	/*try {
	if (!file.is_open())
	{
	throw 1;
	}
	}
	catch (int i)
	{
	Exception ex(i);
	ex.Print();
	return;
	}*/
	for (int i = 0; i < this->size - 1; i++) {
		for (int j = 0; j < this->size - i - 1; j++)
		{
			this->file.seekg(0, ios_base::beg);
			for (int k = 0; k < j; k++)
				getline(this->file, s1);
			for (int t = 0; t<2; t++)
				getline(this->file, s1, ' ');
			getline(this->file, s2);
			for (int t = 0; t < 2; t++)
				getline(this->file, s2, ' ');
			i1 = stoi(s1);
			i2 = stoi(s2);
			if (i1 > i2)
			{
				this->file.seekg(0, ios_base::beg);
				pos = this->file.tellg();
				for (int k = 0; k <= j; k++) {
					getline(this->file, s1);
					pos = this->file.tellg();
				}
				tmp = s1;
				getline(this->file, s2);
				this->file.seekg(0, ios_base::beg);
				for (int k = 0; k < j; k++) {
					getline(this->file, s1);
				}
				pos = this->file.tellg();
				this->file.seekg(pos, ios_base::beg);
				this->file << s2 << '\n';
				this->file << tmp << '\n';
			}
		}
	}
	this->close();
}
