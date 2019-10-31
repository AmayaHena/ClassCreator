/*
** EPITECH PROJECT, 2019
** ClassCreatorWIP
** File description:
** State
*/

#include "State.hpp"

void State::createHpp(Parser &p, Writer &w, const std::vector<std::string> &file, const std::string &s)
{
	w.setFile(file);

	if (p.getInheritance()) {
		w.setInclude(p.getProjectName() + ".hpp");
		w.setInheritance(p.getProjectName());
	}
	if (p.getFolders()) {
		_d.createDir(p.getProjectName() + "/inc", s);
		w.create(s, p.getProjectName() + "/inc/" + s, ".hpp");
		return;
	}
	w.create(s, p.getProjectName() + "/inc", ".hpp");
}

void State::createCpp(Parser &p, Writer &w, const std::vector<std::string> &file, const std::string &s)
{
	w.setFile(file);

	if (p.getInheritance())
		w.setInheritance(p.getProjectName());
	if (p.getFolders()) {
		_d.createDir(p.getProjectName() + "/src", s);
		w.setInclude(s + "/" + s + ".hpp");
		w.create(s, p.getProjectName() + "/src/" + s, ".cpp");
		return;
	}
	w.setInclude(s + ".hpp");
	w.create(s, p.getProjectName() + "/src", ".cpp");
}

void State::createHppRoot(Parser &p, Writer &w, const std::vector<std::string> &file, const std::string &s)
{
	w.setFile(file);
	w.create(s, p.getProjectName() + "/inc", ".hpp");
}

void State::createCppRoot(Parser &p, Writer &w, const std::vector<std::string> &file, const std::string &s)
{
	w.setFile(file);
	w.setInclude("../inc/" + s + ".hpp");
	w.create(s, p.getProjectName() + "/src", ".cpp");
}

void State::generateMain(Parser &p, Writer &w, const std::vector<std::string> &file, const std::vector<std::string> &inc)
{
	if (!p.getMain())
		return;
	w.setFile(file);
	w.setInc(inc);
	w.create("main", p.getProjectName(), "main");
}

void State::generateMakefile(Parser &p, Writer &w, const std::vector<std::string> &file, const std::vector<std::string> &src)
{
	if (!p.getMakefile())
		return;
	w.setFile(file);
	w.setSrc(src);
	w.create("Makefile", p.getProjectName(), "Makefile");
}

void State::generateCMake(Parser &p, Writer &w, const std::vector<std::string> &file, const std::vector<std::string> &inc, const std::vector<std::string> &src)
{
	if (!p.getCMake())
		return;
	w.setFile(file);
	w.setInc(inc);
	w.setSrc(src);
	w.create("CMakeLists", p.getProjectName(), "CMake");
}