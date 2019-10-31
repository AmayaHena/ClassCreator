/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(const std::vector<std::string> &v){ _p.parsingProceed(v); }

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
	Core::fillPath(_p.getProjectName());
	if (_p.getSubFiles().size() <= 0)
		return true;

	std::vector<std::string> subfiles = _p.getSubFiles();
	for (const std::string &file: subfiles) {
		_s.createHpp(_p, _w, _f.getFileHpp(), file);
		_s.createCpp(_p, _w, _f.getFileCpp(), file);
		if (_p.getFolders())
			Core::fillPath(file + "/" + file);
		else
			Core::fillPath(file);
	}
	return true;
}

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
	if (!_f.loadConfig(_p.getMain(), _p.getMakefile(), _p.getCMake()))
		return false;
	if (_p.getMain())
		_src.push_back("main.cpp");

	_w.setHeader(_f.getHeader());
	_d.createDir(".", _p.getProjectName());
	Core::generateCode();
	_s.generateMain(_p, _w, _f.getMain(), _inc);
	_s.generateMakefile(_p, _w, _f.getMakefile(), _src);
	_s.generateCMake(_p, _w, _f.getCMake(), _inc, _src);
	if ((_p.getMakefile() || _p.getCMake()) && _p.getMain())
		Core::buildProject();
	return true;
}
