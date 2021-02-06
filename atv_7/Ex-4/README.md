- É possível adicionar uma função membro na classe Derived que chama a função read()?

R: Sim. Pois o método read é protegido e, embora não seja acessível para o usuário, é 
acessível para os membros da própria classe e de suas classes derivadas.

- Alterando a herança para private, ainda assim é possível adicionar uma função membro na classe Derived que chama a função read()?

R: Ainda será possível chamar o método read a partir da classe Derived, porém ele será um método privado, então a função membro deve
chamar o método internamente e retornar o valor de interesse.

- É possível chamar a função read() a partir de um objeto do tipo Derived?

R: Não é possível. Pois a função read será protegida ou privada nos casos citados, portanto inacessível externamente para as instân-
cias da classe.

- Modifique o código [...]. É possível chamar read() a partir de uma função membro da classe Derived2? E o método value()?

R: Sim, é possível chamar o método read, tendo em vista que a classe Derived2 tem a mesma interface que Derived, que herda
da classe Base e tem acesso aos seus métodos protegidos. O método value também é acessível, tendo em vista que ele é público
na base e protegido em Derived, se Derived2 herda de Derived com a keyword public, ela tem a mesma interface e então tem acesso
ao método value() também.