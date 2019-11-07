/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** Core
*/

#include "Core.hpp"

/* CLASS */
#include "Architecture.hpp"

void Core::fillPath(const std::string &s)
{
	_inc.push_back("inc/" + s + ".hpp");
	_src.push_back("src/" + s + ".cpp");
}

bool Core::architectCode()
{
	Architecture a;
	std::vector<std::string> arch_comp = a.completePartial(_arch);
	std::vector<std::string> tmp;
	std::string path;

	for (const std::string &s: arch_comp) {
		tmp = a.cutLine(s);
		std::string path_past = _p.getProjectName();
		for (unsigned int i = 0; i < tmp.size(); i++)  {
			path = path +  "/" + tmp[i];
			if (_d.createDir(_p.getProjectName() + "/inc" + path)) {
				_s.createHppArch(_p, _w, _f.getFileHpp(), tmp, path, i, path_past);
				if (_p.getInterface())
					_s.createInterfaceArch(_p, _w, _f.getFileInterface(), tmp, path, i, path_past);
				_inc.push_back("inc" + path + "/" + tmp[i] + ".hpp");
			}
			if (_d.createDir(_p.getProjectName() + "/src" + path)) {
 				_s.createCppArch(_p, _w, _f.getFileCpp(), tmp, path, i);
				_src.push_back("src" + path + "/" + tmp[i] + ".cpp");
			}
			path_past = path;
			path.clear();
		}
		tmp.clear();
	}
	return true;
}

void Core::minimalCode()
{
	if (_p.getMain())
		_src.push_back("main.cpp");
	_w.setHeader(_f.getHeader());
	_d.createDir(".", _p.getProjectName());
	_d.createDir(_p.getProjectName(), "inc");
	_d.createDir(_p.getProjectName(), "src");
	_s.createHppRoot(_p, _w, _f.getFileHpp(), _p.getProjectName());
	_s.createCppRoot(_p, _w, _f.getFileCpp(), _p.getProjectName());
	if (_p.getInterface())
		_s.createInterfaceRoot(_p, _w, _f.getFileInterface(), _p.getProjectName());
	Core::fillPath(_p.getProjectName());
}

bool Core::generateCode()
{
	if (_p.getArchitecture().empty() && !_p.getSubFiles().empty()) {
		for (const std::string &s : _p.getSubFiles())
			_arch.push_back("- " + s);
	}
	if (!_p.getArchitecture().empty()) {
		_arch = _f.loadFile(_p.getArchitecture(), true);
		if (_arch.empty())
			return false;
	}
	Core::minimalCode();
	if (!Core::architectCode())
		return false;
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

bool Core::run(const std::vector<std::string> &v)
{
	if (!_p.parsingProceed(v)) {
		std::cout << "use helper : ./classCreator -h" << std::endl;
		return false;
	}
	if (!_f.loadConfig(_p))
		return false;

	if (!Core::generateCode())
		return false;

	_s.generateMain(_p, _w, _f.getMain(), _inc);
	_s.generateMakefile(_p, _w, _f.getMakefile(), _src);
	_s.generateCMake(_p, _w, _f.getCMake(), _inc, _src);
	if ((_p.getMakefile() || _p.getCMake()) && _p.getMain())
		Core::buildProject();
	return true;
}
