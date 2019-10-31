/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** Writer
*/

/* STD Library */
#include <functional>

/* STD Types Library */
#include <fstream>
#include <string>

#include "Writer.hpp"

Writer::Writer() : _tag_ref("/*#!")
{
	_type[".hpp"] = HPP;
	_type[".cpp"] = CPP;
	_type["main"] = MAIN;
	_type["Makefile"] = MAKE;
	_type["CMake"] = CMAKE;

	_tagMake["ProgramName"] = PROGNAME;
	_tagMake["SrcMakefile"] = SRCMAKE;
	_tagMake["SrcCMake"] = SRCCMAKE;
	_tagMake["IncCMake"] = INCCMAKE;

	_tagHPP["FileName"] = FILENAME;
	_tagHPP["ContructorMethod"] = CONSTRUCTOR;
	_tagHPP["DestructorMethod"] = DESTRUCTOR;
	_tagHPP["IncludeInheritanceHpp"] = INCINH;
	_tagHPP["InheritanceHpp"] = INHHPP;

	_tagCPP["IncludeMain"] = INCMAIN;
	_tagCPP["IncludeCpp"] = INCCPP;
	_tagCPP["InheritanceCpp"] = INHCPP;
	_tagCPP["ConstructorCpp"] = CONSTRUCTORCPP;
	_tagCPP["DestructorCpp"] = DESTRUCTORCPP;
}

void Writer::setHeader(std::vector<std::string> v)
{
	_header = v;
}

void Writer::setFile(const std::vector<std::string> &v)
{
	_file = v;
}

void Writer::setSrc(const std::vector<std::string> &v)
{
	_src = v;
}

void Writer::setInc(const std::vector<std::string> &v)
{
	_inc = v;
}

void Writer::setInheritance(const std::string &s)
{
	_inheritance = s;
}

void Writer::setInclude(const std::string &s)
{
	_include = s;
}

void Writer::cleanRessources()
{
	_of.close();
	_file.clear();
	_src.clear();
	_inc.clear();
	_inheritance.clear();
	_include.clear();
}

int Writer::occurenceNbInS(const std::string &s, const std::string &tag)
{
	int N = s.length();
	int M = tag.length();
	int match = 0;
	int j = 0;

	for (int i = 0; i <= N - M; i++) {
		for (j = 0; j < M; j++)
			if (s[i + j] != tag[j])
				break;
		if (j == M)
			match++;
	}
	return match;
}

void Writer::writeVectorInFile(const std::string &s1, const std::vector<std::string> &v, const std::string &s2)
{
	for (const std::string &s: v)
		_of << s1 << s << s2 << std::endl;
}

std::ofstream Writer::createFile(const std::string &name, const std::string &path, const std::string &type)
{
	std::string s;

	switch (_type[type]) {
		case HPP:
			s = path + "/" + name + type;
			break;
		case CPP:
			s = path + "/" + name + type;
			break;
		case MAIN:
			s = path + "/main.cpp";
			break;
		case MAKE:
			s = path + "/Makefile";
			break;
		case CMAKE:
			s = path + "/CMakeLists.txt";
			break;
	}
	std::ofstream file(s);
	std::cout << "\033[0;32mFile \033[0m" << path << '/' << name << "\033[0;32m created\033[0m" << std::endl;
	return file;
}

void Writer::useTagCpp(const std::string &tag, const std::string &name)
{
	switch (_tagCPP[tag]) {
		case INCMAIN :
			Writer::writeVectorInFile("#include \"", _inc, "\"");
			return;
		case INCCPP :
			_of << "#include \"" << _include << "\"";
			return;
		case INHCPP :
			if (!_inheritance.empty())
				_of << " : " << _inheritance << "()";
			return;
		case CONSTRUCTORCPP :
			_of << name << "::" << name << "()";
			return;
		case DESTRUCTORCPP :
			_of << name << "::~" << name << "()";
			return;
	}
}

void Writer::useTagHpp(const std::string &tag, const std::string &name)
{
	switch (_tagHPP[tag]) {
		case FILENAME :
			_of << name;
			return;
		case CONSTRUCTOR :
			_of << name << "();";
			return;
		case DESTRUCTOR :
			_of << "~" << name << "();";
			return;
		case INCINH :
			if (!_include.empty())
				_of << "#include \"" << _include << "\"";
			return;
		case INHHPP :
			if (!_inheritance.empty())
				_of << " : public " << _inheritance;
			return;
	}
}

void Writer::useTagMake(const std::string &tag, const std::string &path)
{
	switch (_tagMake[tag]) {
		case PROGNAME :
			_of << path;
			return;
		case SRCMAKE :
			Writer::writeVectorInFile("\t\t", _src, "\t\\");
			return;
		case SRCCMAKE :
			Writer::writeVectorInFile("\t", _src, "");
			return;
		case INCCMAKE :
			Writer::writeVectorInFile("\t", _inc, "");
			return;
	}
}

void Writer::useTag(const std::string &tag, const std::string &name, const std::string &path, const std::string &type)
{
	if (tag == "Header") {
		Writer::writeVectorInFile("", _header, "");
		return;
	}
	switch (_type[type]) {
		case HPP :
			Writer::useTagHpp(tag, name);
			return;
		case CPP :
			Writer::useTagCpp(tag, name);
			return;
		case MAIN :
			Writer::useTagCpp(tag, name);
			return;
		case MAKE :
			Writer::useTagMake(tag, path);
			return;
		case CMAKE :
			Writer::useTagMake(tag, path);
			return;
	}
}

void Writer::processTag(const std::string &s, const std::string &name, const std::string &path, const std::string type)
{
	std::string buf;
	int i = 0;
	int j = s.find(_tag_ref, 0);
	int k = Writer::occurenceNbInS(s, _tag_ref);

	for (int m = 0; m != k; m++) {
		while (i < j)
			_of << s[i++];
		while (s[i++] != '!');
		while (s[i] != '*')
			buf += s[i++];
		i += 2;
		Writer::useTag(buf, name, path, type);
		j = s.find(_tag_ref, j + 1);
		buf.clear();
	}
	for (unsigned int pos = i; pos < s.length(); pos++)
		_of << s[pos];
	_of << std::endl;
}

bool Writer::create(const std::string &name, const std::string &path, const std::string type)
{
	_of = Writer::createFile(name, path, type);

	for (const std::string &s: _file) {
		if (Writer::occurenceNbInS(s, _tag_ref) > 0)
			Writer::processTag(s, name, path, type);
		else
			_of << s << std::endl;
	}
	Writer::cleanRessources();
	return true;
}
