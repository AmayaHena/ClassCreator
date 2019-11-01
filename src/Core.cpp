/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** Core
*/

#include "Core.hpp"

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
	/* COMMENT THIS TO CONTINUE */
	std::cout << "\033[1;31mCURRENTLY DEVLOPING THIS FEATURE\033[0m" << std::endl;
	return true;
	/* COMMENT THIS TO CONTINUE */

	std::vector<std::string> arch = _f.loadFile(_p.getArchitecture(), true);

	_s.createHppRoot(_p, _w, _f.getFileHpp(), _p.getProjectName());
	_s.createCppRoot(_p, _w, _f.getFileCpp(), _p.getProjectName());
	if (_p.getInterface())
		_s.createInterfaceRoot(_p, _w, _f.getFileInterface(), _p.getProjectName());
	Core::fillPath(_p.getProjectName());
	if (arch.empty())
		return false;

	for (const std::string &s: arch) {
		(void)s;
		/// string current_name (cf 1)
		/// string current_path (cf 2)

		/// 1 - get name of current level of architecture (from left to right)
		/// always have the current level of arch in a string
		/// maybe create a function that find the current and set the next one in return value

		/// 2 - if needed create the folder
		/// so we have to have the current full path of the architecture level in a string
		/// so if we get deeper in the string we have to += of
		/// there will always be directories for this

		/// 3 - call state (create a new one for it (for : cpp hpp interface))
		/// and set the right include for it and inheritance if needed
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
