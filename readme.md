L'idée c'est de créé un solveur d'équations en utilisant l'héritage pour clarifier les types d'éléments présents dans une équation. Voici une explication de l'idée générale :

## 1. Classes de base et dérivées
- Nous avons défini une classe de base abstraite [`EquationElement`](EquationElement.h) qui représente un élément générique d'une équation. Cette classe contient une méthode virtuelle pure [`isValid()`](Equation.cpp) que chaque classe dérivée doit implémenter.
- Nous avons ensuite créé trois classes dérivées : [`Number`](Number.cpp), [`Operator`](Operator.cpp) et [`Parenthesis`](Parenthesis.cpp), chacune représentant un type spécifique d'élément dans une équation.

## 2. Classe [`Equation`](Equation.cpp)
- La classe [`Equation`](Equation.cpp) est responsable de la gestion et de l'évaluation de l'équation. Elle contient un vecteur d'éléments [`EquationElement*`](EquationElement.h) pour stocker les différents éléments de l'équation.
- Le constructeur de [`Equation`](Equation.cpp) prend une chaîne de caractères représentant l'équation et appelle la méthode [`parseExpression`](Equation.cpp) pour analyser et convertir cette chaîne en objets [`Number`](Number.cpp), [`Operator`](Operator.cpp) et [`Parenthesis`](Parenthesis.cpp).

## 3. Analyse et validation
- La méthode [`parseExpression`](Equation.cpp) lit chaque caractère de l'équation et crée les objets appropriés ([`Number`](Number.cpp), [`Operator`](Operator.cpp), [`Parenthesis`](Parenthesis.cpp)) en fonction du type de caractère.
- La méthode [`isValid`](Equation.cpp) vérifie si l'équation est syntaxiquement correcte en s'assurant que les parenthèses sont équilibrées et que les opérateurs et les nombres sont placés correctement.

## 4. Évaluation de l'équation
- La méthode [`evaluate`](Equation.cpp) utilise deux piles : une pour les valeurs ([`values`](Equation.cpp)) et une pour les opérateurs ([`ops`](Equation.cpp)).
- Elle parcourt les éléments de l'équation, empile les nombres et applique les opérateurs en respectant la priorité et l'associativité des opérateurs.
- Une fonction  [`applyOp`](Equation.cpp) est utilisée pour effectuer les opérations arithmétiques de base.
