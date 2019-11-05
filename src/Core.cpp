/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** Core
*/

#include "Core.hpp"

#include "Architecture.hpp"

Core::Core(const std::vector<std::string> &v) { _p.parsingProceed(v); }

void Core::fillPath(const std::string &s)
{
	_inc.push_back("inc/" + s + ".hpp");
	_src.push_back("src/" + s + ".cpp");
}

bool Core::generateCode()
{
	_d.createDir(_p.getProjectName(), "inc");
	_d.createDir(_p.getProjectName(), "src");

	_s.createHppRoot(_p, _w, _f.getFileHpp(), _p.getProjectName());
	_s.createCppRoot(_p, _w, _f.getFileCpp(), _p.getProjectName());
	if (_p.getInterface())
		_s.createInterfaceRoot(_p, _w, _f.getFileInterface(), _p.getProjectName());
	Core::fillPath(_p.getProjectName());
	if (_p.getSubFiles().size() <= 0)
		return true;

	std::vector<std::string> subfiles = _p.getSubFiles();
	for (const std::string &file: subfiles) {
		_s.createHpp(_p, _w, _f.getFileHpp(), file);
		_s.createCpp(_p, _w, _f.getFileCpp(), file);

		/* --- DEBUG --- */
		if (_p.getInterface())
			std::cout << "THIS IS TRUE" << std::endl;
		/* --- DEBUG --- */

		if (_p.getInterface())
			_s.createInterface(_p, _w, _f.getFileInterface(), file);
		if (_p.getFolders())
			Core::fillPath(file + "/" + file);
		else
			Core::fillPath(file);
	}
	return true;
}

/* --- CURRENTLY IN DEVLOPEMENT --- */
bool Core::architectCode()
{
	std::cout << "\033[1;31mCURRENTLY DEVLOPING THIS FEATURE\033[0m" << std::endl;
	Architecture a;
	std::vector<std::string> arch = _f.loadFile(_p.getArchitecture(), true);

	/* UNCOMMENT TO TEST */
	_d.createDir(_p.getProjectName(), "inc");
	_d.createDir(_p.getProjectName(), "src");
	_s.createHppRoot(_p, _w, _f.getFileHpp(), _p.getProjectName());
	_s.createCppRoot(_p, _w, _f.getFileCpp(), _p.getProjectName());
	if (_p.getInterface())
		_s.createInterfaceRoot(_p, _w, _f.getFileInterface(), _p.getProjectName());
	Core::fillPath(_p.getProjectName());
	/* UNCOMMENT TO TEST */

	if (arch.empty())
		return false;

	/* --- DEBUG --- */
	/* std::cout << "--- DEBUG ---" << std::endl;
	for (unsigned int i = 0; i <= arch.size(); i++)
		std::cout << arch[i] << std::endl;
	std::cout << std::endl; */
	/* --- DEBUG --- */

	std::vector<std::string> arch_comp = a.completePartial(arch);
	std::vector<std::string> tmp;

	/* --- DEBUG --- */
	/* std::cout << "--- DEBUG ---" << std::endl;
	for (unsigned int i = 0; i <= arch_comp.size(); i++)
		std::cout << arch_comp[i] << std::endl; */
	/* --- DEBUG --- */

	for (const std::string &s: arch_comp) {
		/// 3 - Create dir & file
		/// Read the vector v (as on the example above), by begining at i = 2
		/// Create dir for it by following the return value of method of Dir object
		/// create the file or not
		/// If the creation of dir doesn t exsit call State object
		/// to create the file, by sending all the ressources needed

		tmp = a.cutLine(s);

		/* --- DEBUG --- */
		/* std::cout << "--- B ---" << std::endl;
		for (const std::string &s : tmp)
			std::cout << "s : " << s << std::endl;
		std::cout << "--- E ---" << std::endl << std::endl; */
		/* --- DEBUG --- */

		std::string path;
		std::string path_past = _p.getProjectName();
		std::string path_comp;

		/* --- DEBUG --- */
		/* for (unsigned int i = 0; i < tmp.size(); i++)  {
			path = path +  "/" + tmp[i];

			std::cout << "--- BEGIN ---" << std::endl;
			std::cout << "tmp[i] : " << tmp[i] << std::endl;
			std::cout << "path : " << path << std::endl;


			std::cout << "HPP CREATE" << std::endl;
			std::cout << "INH" << std::endl;
			if (i == 0)
				std::cout << "include : " << _p.getProjectName() << ".hpp" << std::endl;
			else
				std::cout << "include : " << path << "/" << tmp[i] <<".hpp" << std::endl;
			if (i == 0)
				std::cout << "inheritance : " << _p.getProjectName() << std::endl;
			else
				std::cout << "inheritance : " << tmp[i - 1] << std::endl;
			std::cout << "INT" << std::endl;
			if (i == 0)
				std::cout << "include : " << "I" << _p.getProjectName() << ".hpp" << std::endl;
			else
				std::cout << "include : " << path << "/I" << tmp[i] << ".hpp" << std::endl;
			if (i == 0)
				std::cout << "inheritance : " << "I" << _p.getProjectName() << std::endl;
			else
				std::cout << "incheritance : " << "I" << tmp[i - 1] << std::endl;
			std::cout << "--- END ---" << std::endl << std::endl << std::endl;


			std::cout << "CPP CREATE" << std::endl;
			std::cout << "INH" << std::endl;
			std::cout << "inheritance : " << tmp[i] << std::endl;

			std::cout << "INT" << std::endl;
			std::cout << "inheritance : " << "I" << tmp[i] << std::endl;

			std::cout << "GENERAL" << std::endl;
			if (i == 0)
				std::cout << "include : " <<  path << "/" << tmp[i] << "/I" << tmp[i] << ".hpp" << std::endl;
			else
				std::cout << "include : " << path << "/I" << tmp[i] << ".hpp" << std::endl;


			std::cout << "INTERFACE CREATE" << std::endl;
			std::cout << "INH" << std::endl;
			if (i == 0)
				std::cout << "include : " << "I" << _p.getProjectName() << ".hpp" << std::endl;
			else
				std::cout << "include : " << path_past << "/" << tmp[i - 1] << ".hpp" << std::endl;

			if (i == 0)
				std::cout << "inheritance : " << "I" << _p.getProjectName() << std::endl;
			else
				std::cout << "inheritance : " << "I" << tmp[i - 1] << std::endl;
			std::cout << "--- END ---" << std::endl << std::endl << std::endl; */
			/* --- DEBUG --- */

			path_comp = _p.getProjectName() + "/inc" + path;
			if (_d.createDir(path_comp)) {
			}

			path_comp = _p.getProjectName() + "/src" + path;
			if (_d.createDir(path_comp)) {
			}
			path_past = path;
		}
		tmp.clear();
	}
	return true;
}
/* --- CURRENTLY IN DEVLOPEMENT --- */

void Core::buildProject()
{
	std::string s;

	if (_p.getMakefile() == true)
		s = "make && make clean";
	if (_p.getCMake() == true)
		s = "cmake CMakeLists.txt && make";
	chdir(_p.getProjectName().c_str());
	system(s.c_str());
}

bool Core::run()
{
	if (!_f.loadConfig(_p))
		return false;
	if (_p.getMain())
		_src.push_back("main.cpp");

	_w.setHeader(_f.getHeader());
	_d.createDir(".", _p.getProjectName());
	if (_p.getArchitecture().empty())
		Core::generateCode();
	else
		if (!Core::architectCode())
			return false;
	_s.generateMain(_p, _w, _f.getMain(), _inc);
	_s.generateMakefile(_p, _w, _f.getMakefile(), _src);
	_s.generateCMake(_p, _w, _f.getCMake(), _inc, _src);
	if ((_p.getMakefile() || _p.getCMake()) && _p.getMain())
		Core::buildProject();
	return true;
}
