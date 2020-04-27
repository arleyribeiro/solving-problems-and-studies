import math 

area_para_pintar = float(input("Insira o tamanho em m² da área a ser pintada: "))

# Constantes
COBERTURA_DA_TINTA_LITRO_POR_METRO_QUADRADO = 6
QUANTIDADE_TINTA_LATA = 18
PRECO_POR_LATA = 80
QUANTIDADE_TINTA_GALAO = 3.6
PRECO_POR_GALAO = 25

quantidade_necessaria_de_tinta = area_para_pintar / COBERTURA_DA_TINTA_LITRO_POR_METRO_QUADRADO
quantidade_galoes = 0
quantidade_latas = math.floor(quantidade_necessaria_de_tinta / QUANTIDADE_TINTA_LATA)
quantidade_restante_tinta = quantidade_necessaria_de_tinta % QUANTIDADE_TINTA_LATA

if (quantidade_restante_tinta > QUANTIDADE_TINTA_GALAO * 3):
    quantidade_latas += 1
else:
    quantidade_galoes += math.ceil(quantidade_restante_tinta / QUANTIDADE_TINTA_GALAO)

if quantidade_latas > 0 and quantidade_galoes == 0:
    print("Comprar apenas ", quantidade_latas, "latas " if quantidade_latas > 1 else " lata")
elif quantidade_latas == 0 and quantidade_galoes > 0:
    print("Comprar apenas ", quantidade_galoes, "galoes " if quantidade_galoes > 1 else " galoes")
elif quantidade_latas > 0 and quantidade_galoes > 0:
    print("Comprar apenas ", quantidade_latas, "latas e" if quantidade_latas > 1 else " lata e ", quantidade_galoes, " galoes" if quantidade_galoes > 1 else " galoes")
else:
    print("Área informada inválida")

valor_total = quantidade_latas * PRECO_POR_LATA + quantidade_galoes * PRECO_POR_GALAO
print("Valor total: R$ %.2f " % valor_total)