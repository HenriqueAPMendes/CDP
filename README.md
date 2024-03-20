# Como rodar os scripts

- Se quiser simplesmente listar todos os problemas salvos, rode o comando
  ```python3 listproblems.py```
  - Existem algumas opções que podem ser adicionadas:
      -  --done / -d : lista os problemas já feitos
      -  --undone / -u : lista os problemas que ainda não foram feitos
      -  --all / -a : lista todos os problemas
      Se não colocar nenhuma opção, o padrão é mostar todas as undone
- Se quiser codar um problema, rode o comando
  ```python3 getproblem.py```
  Você pode colocar a opção --random / -r e o script retornará um problema aleatório, ou,
  se não colocar a opção, ele irá te retornar o primeiro problema da fila (o mais antigo)
- Quando passar o problema, rode o seguinte script:
  ```python3 markasdone.py <url>```
  Esse script irá marcar o problema como um problema já feito
- Para adicionar um problema, rode o script:
  ```python3 addproblem.py <url> [categories...]```
  Você pode passar quantas categorias quiser após a url, e elas serão adicionadas e marcadas junto do problema
