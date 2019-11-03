/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** Architechture
*/

#include "Architecture.hpp"

std::vector<std::string> Architecture::completePartial(std::vector<std::string> &v)
{
    /// 1 - Complete partials lines in string of vector
    /// if a line is empty delete it
    ///
    /// Example :
    /// Item - Potion - Heal
    ///               - Damage
    ///(empty line)
    /// Into :
    /// *Project Name* - inc - Item - Potion - Heal
    /// *Project Name* - src - Item - Potion - Heal
    /// *Project Name* - inc - Item - Potion - Damage
    /// *Project Name* - src - Item - Potion - Damage
    ///
    /// Algorithmic pseudo code :
    /// If the current line is empty reset ressource and take the next line for ressources
    /// Take the last '-' position on the line above
    /// Take all the char before (we'll call it : std::string midle)
    /// Take the current line delete all the ' ' (we'll call it : std::string end)
    /// Push it into the vector will be return as :
    /// *Project name* + "inc" + middle + end
    /// *Project name* + "src" + middle + end

    std::vector<std::string> vector;
    (void)vector;
    (void)v;
    return vector;
}

std::vector<std::string> Architecture::cleanVector(std::vector<std::string> &v)
{
    /// 2 - Delete all spaces & replace all '-' by '/'
    /// By for loop range

    std::vector<std::string> vector;
    (void)vector;
    (void)v;
    return vector;
}

std::vector<std::string> Architecture::cutLine(std::string &s)
{
    /// 3 - Send the current line to a cutter
    /// Wich return a vector of string with a string by dir
    ///
    /// Example :
    /// *Project Name*/inc/Item/Potion/Heal
    /// *Project Name*/src/Item/Potion/Heal
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

    std::vector<std::string> vector;
    (void)vector;
    (void)s;
    return vector;
}