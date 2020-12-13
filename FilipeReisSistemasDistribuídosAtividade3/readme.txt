Árvore no linux
Mova-se para esse local ou outro de sua preferência
/home/nome_usuario/Documents/202020907315FilipeReisSistemasDistribuídosAtividade3

veja o arquivo runningrpc.py e descomente as linhas 4(quatro) e 7 (sete) e comente da linha 12 (doze) em diante

Em meu computador eu usei
sudo cp rpcmodule.py /usr/lib/python3.6/site-packages/

Agora recomente as linhas 4(quatro) e 7 (sete) no arquivo e descomente da linha 12 (doze) em diante

Eu instanciei dois terminais 
Terminal 1 (um) - roda script que simula servidor e a trilha correta depende da implementação da sua distribuição Linux
>python3 /usr/bin/rpyc_classic

Terminal 2 (dois) - roda meu script conversando com o servidor e utilizando RPC
> python3 runningrpc.py 