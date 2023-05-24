@rem WdNisSvc Выводимое_имя: Служба проверки сети антивирусной программы Microsoft Defender (STOPPABLE, NOT_PAUSABLE, IGNORES_SHUTDOWN)
@rem WinDefend Выводимое_имя: Служба антивирусной программы Microsoft Defender (NOT_STOPPABLE, NOT_PAUSABLE, ACCEPTS_SHUTDOWN)
sc stop WdNisSvc
sc stop WinDefend
pause
