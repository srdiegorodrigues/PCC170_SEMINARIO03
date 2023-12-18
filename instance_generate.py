import random
import numpy as np

def gerar_instancia(tamanho):
    instancia = []
    for i in range(tamanho):
        instancia.append((i, random.randint(1, 100), random.randint(1, 100)))
    return instancia

def salvar_instancia(instancia, nome_arquivo):
    np.savetxt(nome_arquivo, instancia, fmt='%d', delimiter='\t')

# Gerar instâncias de tamanhos específicos
instancia_tamanho_25 = gerar_instancia(25)
instancia_tamanho_50 = gerar_instancia(50)
instancia_tamanho_75 = gerar_instancia(75)
instancia_tamanho_100 = gerar_instancia(100)

# Salvar instâncias em arquivos txt
salvar_instancia(instancia_tamanho_25, 'instancia_tamanho_25.txt')
salvar_instancia(instancia_tamanho_50, 'instancia_tamanho_50.txt')
salvar_instancia(instancia_tamanho_75, 'instancia_tamanho_75.txt')
salvar_instancia(instancia_tamanho_100, 'instancia_tamanho_100.txt')

print("Instâncias salvas em arquivos txt.")
