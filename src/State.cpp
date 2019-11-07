/*
** EPITECH PROJECT, 2019
** ClassCreatorWIP
** File description:
** State
*/

#include "State.hpp"

void State::createHppArch(Parser &p, Writer &w, const std::vector<std::string> &file, const std::vector<std::string> &tmp, std::string &path, unsigned int i, std::string &past_path)
{
	w.setFile(file);

	std::string path_no_slash = path;
	path_no_slash.erase(path_no_slash.begin());

	std::string past_path_no_slash = past_path;
	past_path_no_slash.erase(past_path_no_slash.begin());

	if (p.getInheritance() && !p.getInterface()) {
		if (i == 0) {
			w.setInclude(p.getProjectName() + ".hpp");
			w.setInheritance(p.getProjectName());
		} else {
			w.setInclude(past_path_no_slash + "/" + tmp[i - 1] + ".hpp");
			w.setInheritance(tmp[i - 1]);
		}
	}
	if (p.getInterface()) {
		w.setInclude(path_no_slash + "/I" + tmp[i] + ".hpp");
		w.setInheritance("I" + tmp[i]);
	}
	w.create(tmp[i], p.getProjectName() + "/inc" + path, ".hpp");
}

void State::createCppArch(Parser &p, Writer &w, const std::vector<std::string> &file, const std::vector<std::string> &tmp, std::string &path, unsigned int i)
{
	w.setFile(file);

	std::string path_no_slash = path;
	path_no_slash.erase(path_no_slash.begin());

	if (p.getInheritance()) {
		if (i == 0)
			w.setInheritance(p.getProjectName());
		else
			w.setInheritance(tmp[i - 1]);
	}
	if (p.getInterface())
		w.setInheritance("I" + tmp[i]);
	if (i == 0)
		w.setInclude(path_no_slash + "/" + tmp[i] + ".hpp");
	else
		w.setInclude(path_no_slash + "/" + tmp[i] + ".hpp");
	w.create(tmp[i], p.getProjectName() + "/src" + path, ".cpp");
}

void State::createInterfaceArch(Parser &p, Writer &w, const std::vector<std::string> &file, const std::vector<std::string> &tmp, std::string &path, unsigned int i, std::string &past_path)
{
	w.setFile(file);

	std::string path_no_slash = past_path;
	path_no_slash.erase(path_no_slash.begin());

	if (p.getInheritance()) {
		if (i == 0) {
			w.setInclude("I" + p.getProjectName() + ".hpp");
			w.setInheritance("I" + p.getProjectName());
		} else {
			w.setInclude(path_no_slash + "/" + "I" + tmp[i - 1] + ".hpp");
			w.setInheritance("I" + tmp[i - 1]);
		}
	}
	w.create("I" + tmp[i], p.getProjectName() + "/inc" + path, ".hpp");
}

void State::createHppRoot(Parser &p, Writer &w, const std::vector<std::string> &file, const std::string &s)
{
	w.setFile(file);
	if (p.getInterface()) {
		w.setInclude("I" + p.getProjectName() + ".hpp");
		w.setInheritance("I" + p.getProjectName());
	}
	w.create(s, p.getProjectName() + "/inc", ".hpp");
}

void State::createCppRoot(Parser &p, Writer &w, const std::vector<std::string> &file, const std::string &s)
{
	w.setFile(file);
	w.setInclude("../inc/" + s + ".hpp");
	w.create(s, p.getProjectName() + "/src", ".cpp");
}

void State::createInterfaceRoot(Parser &p, Writer &w, const std::vector<std::string> &file, const std::string &s)
{
	w.setFile(file);
	w.create("I" + s, p.getProjectName() + "/inc", ".hpp");
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