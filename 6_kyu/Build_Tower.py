#@see https://www.codewars.com/kata/576757b1df89ecf5bd00073b
def tower_builder(n_floors):
    base_width = n_floors * 2 - 1
    tower = []
    
    for n_floor in range(n_floors):
        n_dots_on_floor = (n_floor + 1) * 2 - 1
        n_spaces_on_floor = (base_width - n_dots_on_floor) // 2
        tower.append(' ' * n_spaces_on_floor + '*' * n_dots_on_floor + ' ' * n_spaces_on_floor)
        
    return tower

