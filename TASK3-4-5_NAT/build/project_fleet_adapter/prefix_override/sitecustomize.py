import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/usuario/Documentos/GitHub/IR2134/TASK3y4_NAT/install/project_fleet_adapter'
