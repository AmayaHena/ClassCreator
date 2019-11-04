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

/* 	_s.createHppRoot(_p, _w, _f.getFileHpp(), _p.getProjectName());
	_s.createCppRoot(_p, _w, _f.getFileCpp(), _p.getProjectName());
	if (_p.getInterface())
		_s.createInterfaceRoot(_p, _w, _f.getFileInterface(), _p.getProjectName());
	Core::fillPath(_p.getProjectName()); */
	if (arch.empty())
		return false;

	/* --- DEBUG --- */
	std::cout << "--- DEBUG ---" << std::endl;
	for (unsigned int i = 0; i <= arch.size(); i++)
		std::cout << arch[i] << std::endl;
	std::cout << std::endl;
	/* --- DEBUG --- */

	std::vector<std::string> v = a.completePartial(arch);

	/* --- DEBUG --- */
	std::cout << "--- DEBUG ---" << std::endl;
	for (unsigned int i = 0; i <= v.size(); i++)
		std::cout << v[i] << std::endl;
	/* --- DEBUG --- */

	for (const std::string &s: arch) {
		(void)s;
		/// 1 - Complete partials lines in string of vector
		/// if a line is empty delete it
		/// clean lines here btw
		///
		/// Example :
		/// Item - Potion - Heal
		///               - Damage
		///(empty line)
		/// Into :
		/// /Item/Potion/Heal
		/// /Item/Potion/Damage
		///
		/// Algorithmic pseudo code :
		/// If the current line is empty reset ressource and take the next line for ressources
		/// Take the last '-' position on the line above
		/// Take all the char before (we'll call it : std::string middle)
		/// Take the current line delete all the ' ' (we'll call it : std::string end)
		/// Push it into the vector will be return as :
		/// begin + end
		/// begin + end

		/// 2 - Send the current line to a cutter
		/// Wich return a vector of string with a string by dir
		///
		/// Example :
		/// /Item/Potion/Heal
		/// /Item/Potion/Heal
		/// Into :
		/// (Considering, std::vector<std::string> v)
		/// v[0] = *Project Name*
		/// v[1] = "inc"
		/// v[2] = "Item"
		/// v[3] = "Potion"
		/// v[4] = "Heal"
		///
		/// v[0] = *Project Name*
		/// v[1] = "src"
		/// v[2] = "Item"
		/// v[3] = "Potion"
		/// v[4] = "Heal"

		/// 3 - Create dir & file
		/// Read the vector v (as on the example above), by begining at i = 2
		/// Create dir for it by following the return value of method of Dir object
		/// create the file or not
		/// If the creation of dir doesn t exsit call State object
		/// to create the file, by sending all the ressources needed
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
