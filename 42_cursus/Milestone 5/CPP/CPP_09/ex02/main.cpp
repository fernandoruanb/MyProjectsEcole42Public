/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:54:12 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/16 14:31:27 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "PmergeMe.hpp"

//static void	studyTimeListVectorsSets(void);

static bool	ft_atoi_check(const char *argv)
{
	long	result;
	long	signal;
	long	index;

	result = 0;
	signal = 1;
	index = 0;
	while (argv[index] == '\n' || argv[index] == '\f' || argv[index] == '\v'
		|| argv[index] == '\t' || argv[index] == '\r')
		index++;
	while (argv[index] >= '0' && argv[index] <= '9')
	{
		result *= 10;
		result += argv[index] - '0';
		if (result > INT_MAX)
			return (0);
		index++;
	}
	return (1);
}

static bool	parser(int argc, char **argv, std::vector<unsigned int> &vectorBase, std::list<unsigned int> &listBase)
{
	long long	count;
	long long	index;
	long long	value;
	std::string	checker;

	count = 1;
	while (count < argc)
	{
		index = 0;
		if (argv[count][0] == '\0')
			return (0);
		checker = argv[count];
		while (argv[count][index] != '\0')
		{
			if (argv[count][index] >= '0' && argv[count][index] <= '9')
					index++;
			else
				return (0);
		}
		if (!ft_atoi_check(argv[count]))
			return (0);
		std::stringstream ss(argv[count]);
		ss >> value;
		vectorBase.push_back(value);
		listBase.push_back(value);
		count++;
	}
	return (1);
}

static void	mountVectorEven(std::vector<unsigned int> vectorBase, std::vector<unsigned int> &vectorHigh, std::vector<unsigned int> &vectorLow)
{
	vectorLow.clear();
	vectorHigh.clear();
	long long	index;

	index = 0;
	while (index < vectorBase.size())
	{
		if (index + 1 >= vectorBase.size())
		{
			vectorLow.push_back(vectorBase[index]);
			break ;
		}
		else if (vectorBase[index] < vectorBase[index + 1])
		{
			vectorLow.push_back(vectorBase[index]);
			vectorHigh.push_back(vectorBase[index + 1]);
		}
		else
		{
			vectorLow.push_back(vectorBase[index + 1]);
			vectorHigh.push_back(vectorBase[index]);
		}
		index += 2;
	}
}

static void	mountListEven(std::list<unsigned int> listBase, std::list<unsigned int> &listHigh, std::list<unsigned int> &listLow)
{
	listLow.clear();
	listHigh.clear();
	std::list<unsigned int>::iterator itl = listBase.begin();
	std::list<unsigned int>::iterator nl;

	while (itl != listBase.end())
	{
		nl = itl;
		++nl;
		if (nl == listBase.end())
		{
			listLow.push_back(*itl);
			break ;
		}
		else if (*itl < *nl)
		{
			listHigh.push_back(*nl);
			listLow.push_back(*itl);
		}
		else
		{
			listHigh.push_back(*itl);
			listLow.push_back(*nl);
		}
		itl = nl;
		++itl;
	}
}

int	main(int argc, char **argv)
{
	double	startVector;
	double	endVector;
	double	startList;
	double	endList;

	if (argc < 2)
	{
		std::cerr << RED "Error: You need to put arguments" RESET << std::endl;
		return (1);
	}

	std::vector<unsigned int> vectorBase;
	std::list<unsigned int> listBase;
	std::vector<unsigned int> vectorHigh;
	std::vector<unsigned int> vectorLow;
	std::list<unsigned int> listHigh;
	std::list<unsigned int> listLow;
	std::vector<unsigned int> jacobVector;
	std::vector<unsigned int> orderVector;
	std::list<unsigned int> orderList;
	std::list<unsigned int> jacobList;
	std::list<unsigned int> copyListHigh;
	std::vector<unsigned int> copyVectorHigh;

	startVector = std::clock();
	startList = std::clock();
	if (!parser(argc, argv, vectorBase, listBase))
	{
		std::cerr << RED "Error: Invalid input detected." RESET << std::endl;
		return (1);
	}
	mountVectorEven(vectorBase, vectorHigh, vectorLow);
	copyVectorHigh = vectorHigh;
	sortHighVector(vectorHigh);
	mountListEven(listBase, listHigh, listLow);
	copyListHigh = listHigh;
	sortHighList(listHigh);
	generateVectorJacobsthal(jacobVector, orderVector, vectorLow.size());
	generateListJacobsthal(jacobList, orderList, listLow.size());
	doTheMagicVector(vectorHigh, vectorLow, orderVector);
	endVector = std::clock();
	doTheMagicList(listHigh, listLow, orderList);
	endList = std::clock();
	
	// Comunicate the results to USER

	std::cout << BRIGHT_MAGENTA "Before: " RESET;
	showVector(vectorBase);
	std::cout << BRIGHT_MAGENTA "Before: " RESET;
	showList(listBase);
	std::cout << BRIGHT_MAGENTA "After: " RESET;
	showVector(vectorHigh);
	std::cout << LIGHT_BLUE << "VECTOR Time: " << std::fixed << std::setprecision(8) << YELLOW << (endVector - startVector) * 1000000 / CLOCKS_PER_SEC << ORANGE " us" RESET << std::endl;
	std::cout << BRIGHT_MAGENTA "After: " RESET;
	showList(listHigh);
	std::cout << LIGHT_BLUE << "LIST Time: " << std::fixed << std::setprecision(8) << YELLOW <<(endList - startList) * 1000000 / CLOCKS_PER_SEC << ORANGE " us" RESET << std::endl;
	std::cout << std::endl;
	isVectorSorted(vectorHigh);
	isListSorted(listHigh);
	std::cout << std::endl;

	std::cout << MAGENTA << std::string(10, '=') << WHITE "vectorHigh and ListHigh" << MAGENTA << std::string(10, '=') << std::endl;
	showVector(copyVectorHigh);
	showList(copyListHigh);

	std::cout << MAGENTA << std::string(10, '=') << WHITE "vectorLow and ListLow" << MAGENTA << std::string(10, '=') << std::endl;
	showVector(vectorLow);
	showList(listLow);

	std::cout << MAGENTA << std::string(10, '=') << WHITE "jacobVector and jacobList" << MAGENTA << std::string(10, '=') << std::endl;
	showVector(jacobVector);
	showList(jacobList);

	std::cout << MAGENTA << std::string(10, '=') << WHITE "orderVector and orderList" << MAGENTA << std::string(10, '=') << std::endl;
	showVector(orderVector);
	showList(orderList);
	//std::cout << std::endl;
	//studyTimeListVectorsSets();
	return (0);
}

/*static void	studyTimeListVectorsSets(void)
{
	std::cout << BRIGHT_MAGENTA << std::string(60, '=') << RESET << std::endl;
	std::cout << std::string(27, ' ') << BRIGHT_WHITE "TEST 1" RESET << std::endl;
	std::cout << BRIGHT_MAGENTA << std::string(60, '=') << RESET << std::endl;

	std::cout << WHITE "ADDING 1.000.000 VALUES" RESET << std::endl;
	long long	value;
	double	start;
	double	end;
	std::list<int> testList;
	std::vector<int> testVector;
	std::set<int> testSet;

	value = 0;
	start = std::clock();
	while (value < 1000000)
	{
		testList.push_back(value);
		value++;
	}
	end = std::clock();
	std::cout << WHITE "KEYWORD: " << GREEN << "RESTAURANT" << std::endl;
	std::cout << ORANGE "The time to put 1.000.000 elements on " << GREEN "LIST " << ORANGE "is " << YELLOW  << (end - start) / CLOCKS_PER_SEC << ORANGE " s" << RESET <<  std::endl;
	start = std::clock();
	value = 0;
	while (value < 1000000)
	{
		testVector.push_back(value);
		value++;
	}
	end = std::clock();
	std::cout << WHITE "KEYWORD: " << GREEN << "HOGWARDS" << std::endl;
	std::cout << ORANGE "The time to put 1.000.000 elements on " << GREEN << "VECTOR " << ORANGE "is " << YELLOW << (end - start) / CLOCKS_PER_SEC << ORANGE " s" << RESET << std::endl;

	value = 0;
	start = std::clock();
	while (value < 1000000)
	{
		testSet.insert(value);
		value++;
	}
	end = std::clock();
	std::cout << WHITE "KEYWORD: " << GREEN "FASTER AND ORGANIZED" << std::endl;
	std::cout << ORANGE "The time to put 1.000.000 elements on " << GREEN << "SET " << ORANGE "is " << YELLOW << (end - start) / CLOCKS_PER_SEC << ORANGE " s" << RESET << std::endl;

	std::cout << BRIGHT_MAGENTA << std::string(60, '=') << RESET << std::endl;
        std::cout << std::string(27, ' ') << BRIGHT_WHITE "TEST 2" RESET << std::endl;
        std::cout << BRIGHT_MAGENTA << std::string(60, '=') << RESET << std::endl;
	std::cout << WHITE "ADDING 1.000.000 VALUES IN FRONT" RESET << std::endl;

	value = 0;
	testList.clear();
	testVector.clear();
	start = std::clock();
	while (value < 1000000)
	{
		testList.push_front(value);
		value++;
	}
	end = std::clock();
	std::cout << WHITE "KEYWORD: " << GREEN << "POINTERS" << std::endl;
	std::cout << ORANGE "The time to put front 1.000.000 elements on " << GREEN << "LIST " << ORANGE "is " << YELLOW << (end - start) / CLOCKS_PER_SEC << ORANGE " s" << RESET << std::endl;
	std::cout << WHITE "KEYWORD: " << GREEN << "INSTRUCTIONS" << std::endl;
	std::vector<int>::iterator exam = testVector.begin();
        value = 0;
        start = std::clock();
        while (value < 1000000)
        {
                exam = testVector.insert(exam, value);
                ++exam;
                value++;
        }
        end = std::clock();
	std::cout << ORANGE "The time to put front 1.000.000 elements on " << GREEN << "VECTOR " << YELLOW << (end - start) / CLOCKS_PER_SEC << ORANGE " s" << RESET << std::endl;

	std::cout << BRIGHT_MAGENTA << std::string(60, '=') << RESET << std::endl;
        std::cout << std::string(27, ' ') << BRIGHT_WHITE "TEST 3" RESET << std::endl;
        std::cout << BRIGHT_MAGENTA << std::string(60, '=') << RESET << std::endl;
	std::cout << WHITE "FINDING RANDOM VALUES" RESET << std::endl;

	std::srand(std::time(NULL));
	value = rand() % 1000000;
	std::list<int>::iterator it = testList.begin();
	start = std::clock();
	while (it != testList.end())
	{
		if (*it == value)
		{
			std::cout << GREEN "Value found: " << YELLOW <<  value << GREEN "!!!" << RESET << std::endl;
			break ;
		}
		++it;
	}
	if (it == testList.end())
		std::cerr << RED "Value is lost!" RESET << std::endl;
	end = std::clock();
	std::cout << WHITE "KEYWORD: " << GREEN "COMPLEXITY" RESET << std::endl;
	std::cout << ORANGE << "The " << GREEN "LIST " << ORANGE << "time to find is: " << YELLOW << (end - start) / CLOCKS_PER_SEC <<  ORANGE " s" << RESET << std::endl;
	std::vector<int>::iterator itV = testVector.begin();
	start = std::clock();
	while (itV != testVector.end())
	{
		if (*itV == value)
		{
			std::cout << GREEN "Value found: " << YELLOW <<  value << GREEN "!!!" << RESET << std::endl;
			break ;
		}
		++itV;
	}
	end = std::clock();
	if (itV == testVector.end())
                std::cerr << RED "Value is lost!" RESET << std::endl;
	std::cout << WHITE << "KEYWORD: " << GREEN "ORGANIZED" RESET << std::endl;
	std::cout << ORANGE << "The " << GREEN "VECTOR " << ORANGE << "time to find is: " << YELLOW << (end - start) / CLOCKS_PER_SEC <<  ORANGE " s" << RESET << std::endl;

	start = std::clock();
	std::set<int>::iterator its = testSet.find(value);
	end = std::clock();
	if (*its == value)
	{
		std::cout << WHITE "KEYWORD: " << GREEN "RED/BLACK Tree" RESET << std::endl;
		std::cout << GREEN "Value found: " << YELLOW << value << GREEN "!!!" << RESET << std::endl;
		std::cout << ORANGE << "The " << GREEN "SET " << ORANGE << "time to find is: " << YELLOW << (end - start) / CLOCKS_PER_SEC <<  ORANGE " s" << RESET << std::endl;
	}
	else
		std::cerr << RED "SET Error: Value is lost!" RESET << std::endl;

	std::cout << BRIGHT_MAGENTA << std::string(60, '=') << RESET << std::endl;
        std::cout << std::string(27, ' ') << BRIGHT_WHITE "TEST 4" RESET << std::endl;
        std::cout << BRIGHT_MAGENTA << std::string(60, '=') << RESET << std::endl;
	std::cout << WHITE "REMOVING 1.000 RANDOM VALUES" RESET << std::endl;
	int	count;

	count = 0;
	start = std::clock();
	while (count < 1000)
	{
		value = rand();
		testList.remove(value);
		count++;
	}
	end = std::clock();
	std::cout << WHITE "KEYWORD: " << GREEN "TASKS" RESET << std::endl;
	std::cout << ORANGE "The " GREEN "LIST" ORANGE " removing values time: " << YELLOW << (end - start) / CLOCKS_PER_SEC << ORANGE " s" RESET << std::endl;
	count = 0;
	start = std::clock();
	std::vector<int>::iterator s = testVector.begin();
	std::vector<int>::iterator e = testVector.end();
	while (count < 1000)
	{
		value = rand();
		std::remove(s, e, value);
		count++;
	}
	end = std::clock();
	std::cout << WHITE "KEYWORD: " << GREEN "SIMPLE" RESET << std::endl;
	std::cout << ORANGE "The " GREEN "VECTOR" ORANGE " removing values time: " << YELLOW << (end - start) / CLOCKS_PER_SEC << ORANGE " s" RESET << std::endl;

	count = 0;
	start = std::clock();
	while (count < 1000)
	{
		value = rand();
		testSet.erase(value);
		count++;
	}
	end = std::clock();
	std::cout << WHITE "KEYWORD: " << GREEN "SIMPLE" RESET << std::endl;
        std::cout << ORANGE "The " GREEN "SET" ORANGE " removing values time: " << YELLOW << (end - start) / CLOCKS_PER_SEC << ORANGE " s" RESET << std::endl;

	std::cout << BRIGHT_MAGENTA << std::string(60, '=') << RESET << std::endl;
        std::cout << std::string(27, ' ') << BRIGHT_WHITE "TEST 5" RESET << std::endl;
        std::cout << BRIGHT_MAGENTA << std::string(60, '=') << RESET << std::endl;
	std::cout << WHITE "REMOVING/INSERTING AT THE SAME TIME" RESET << std::endl;
	testList.clear();
	testVector.clear();
	count = 0;
	start = std::clock();
	while (count < 1000000)
	{
		value = rand();
		testList.push_back(value);
		if (count % 1000 == 0)
		{
			value = rand();
			testList.push_back(value);
			testList.remove(value);
		}
		count++;
	}
	end = std::clock();
	std::cout << WHITE "KEYWORD: " GREEN "EASY" RESET << std::endl;
	std::cout << ORANGE "The " GREEN "LIST " ORANGE "insert/remove tests: " << YELLOW << (end - start) / CLOCKS_PER_SEC << ORANGE << " s" << RESET << std::endl;
	count = 0;
	start = std::clock();
	while (count < 1000000)
	{
		value = rand();
		testVector.push_back(value);
		if (count % 1000 == 0)
		{
			value = rand();
			testVector.push_back(value);
			std::remove(s, e, value);
		}
		count++;
	}
	end = std::clock();
	std::cout << WHITE "KEYWORD: " GREEN "GOD" RESET << std::endl; 
	 std::cout << ORANGE "The " GREEN "VECTOR " ORANGE "insert/remove tests: " << YELLOW << (end - start) / CLOCKS_PER_SEC << ORANGE << " s" << RESET << std::endl;

	count = 0;
	start = std::clock();
	while (count < 1000000)
	{
		value = rand();
		testSet.insert(value);
		if (count % 1000 == 0)
		{
			value = rand();
			testSet.insert(value);
			testSet.erase(value);
		}
		count++;
	}
	end = std::clock();

	 std::cout << WHITE "KEYWORD: " GREEN "THE NEW MODEL" RESET << std::endl;
         std::cout << ORANGE "The " GREEN "SET " ORANGE "insert/remove tests: " << YELLOW << (end - start) / CLOCKS_PER_SEC << ORANGE << " s" << RESET << std::endl;

	 std::cout << LIGHT_BLUE << std::string(60, '=') << RESET << std::endl;
	 std::cout << std::string(18, ' ') << WHITE "Sequence of Jacobsthal" RESET << std::endl;
	 std::cout << LIGHT_BLUE << std::string(60, '=') << RESET << std::endl;

	 std::vector<unsigned int> jacobsthal;
	 unsigned int	mark;
	 unsigned int	index;
	 unsigned int	power;

	 mark = 19;
	 index = 1;
	 jacobsthal.push_back(0);
	 jacobsthal.push_back(1);
	 while (index < mark)
	{
		power = jacobsthal[index] + 2 * jacobsthal[index - 1];
		jacobsthal.push_back(power);
		++index;
	}
	std::vector<unsigned int>::iterator i = jacobsthal.begin();
	std::vector<unsigned int>::iterator f;

	while (i != jacobsthal.end())
	{
		f = i;
		++f;
		if (f != jacobsthal.end())
			std::cout << YELLOW << *i << MAGENTA ", " RESET;
		else
			std::cout << YELLOW << *i << MAGENTA "." RESET << std::endl;
		++i;
	}
}*/
