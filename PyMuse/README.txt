Python MuseClientAPI :

CE README N'EST PAS A JOUR! @TODO

Class:
	- MuseClient					//	Objet user, Evalue en temps reel les valeurs du Muse Headband
	- MuseClientError				//	Objet user, Exeption mere des erreurs possibles dans MuseClient
	- MuseClientProducerThreadBase	//	Objet interne, Encapsule le thread comm
	- MuseClientProducerThread		//	Objet interne herite, Recoit les trames OSC, met à jour MuseInfo
	- MuseInfo						//	Objet interne, Contient la collection d'objets MuseValue en Thread-Safe
	- Osc							//	Objet interne, Parse les trames OSC brut
	- OscUrl						//	Objet interne, Parse uniquement l'url d'une trame OSC brut
	- OscError						//	Objet interne, Exeption des erreurs de format de la trame OSC brut

Detail des class

MuseClient:
	Attribute:
		- server_address			//	Public, Adresse IP du server MuseServer
		- cmd_port					//	Public, Port TCP du server cmd MuseServerCmdThread
		- _keys						//	Prive, Keys Enum de MuseInfo
		- _subscribe_list			//	Prive, Dictionnaire booleen des Keys auquels MuseClient s'est inscrit
		- _cmd_socket				//	Prive, Socket TCP connectee au server MuseServerCmdPort
		- _token					//	Prive, Threading.Queue objet de communication inter-thread
		- _producer					//	Prive, Instance de MuseClientProducerThread

	Method:
		- start						//	Public, Demarre MuseClientProducerThread, recupere le token, connecte la socket cmd
		- stop						//	Public, Envoi la requete de fin de session au MuseServer
		- subscribe					//	Public, Envoi les requetes de souscription a une liste de Keys, au MuseServer, evalue la reponse
		- unsubscribe				//	Public, Envoi les requetes de dessouscription a une liste de Keys, au MuseServer, evalue la reponse
		- is_subscribe				//	Public, Renseigne sur l'etat d'une Keys (souscrit/non souscrit)
		- get_muse_info				//	Public, Evalue la valeur Keys de MuseInfo
		- get_muse_info_str			//	Public, Evalue la valeur Keys de MuseInfo sous forme de chaine
		- get_error					//	Public, Retourne l'erreur potentielle du producer
		- _init_subscribe_list		//	Prive, Initialise la liste de souscription
		- _handle_token				//	Prive, Lit le token dans la Queue et connecte la socket cmd
		- _handle_new_request		//	Prive, Envoi une requete cmd et evalue le retour de MuseSrver

MuseClientError : Exception

MuseClientProducerThreadBase:
	Attribute:
		- server_adress				//	Public, Adresse IP du server MuseServer
		- comm_port					//	Public, Port TCP du server comm MuseServerCommThread
		- _muse_info				//	Prive, Instance de MuseInfo
		- _comm_socket				//	Prive, Socket TCP connectee au server MuseServerCommPort
		- _thread					//	Prive, Threading.thread
		- _token					//	Prive, Threading.Queue objet de communication inter-thread
		- _error					//	Prive, Erreur potentielle

	Method:
		- start						//	Public, Appel la method start de _thread
		- get_muse_info				//	Public, Evalue la valeur Keys de MuseInfo 
		- get_muse_info_str			//	Public, Evalue la valeur Keys de MuseInfo sous forme de chaine
		- get_error					//	Public, Retourne l'erreur potentielle
		- handler					//	Public, Method Handler de _thread

MuseClientProducerThread : MuseClientProducerThreadBase
	Attribute:
	Method:
		- handler					//	Interne, Initialise la connection comm, recoi les trames OSC et met à jour MuseInfo
		- _handle_token				//	Prive, Connecte la socket comm, recoi le token et le pousse dans la queue
		- _maj_muse_info			//	Prive, Met a jour la valeur Keys de MuseInfo

Osc:
	Attribute:
		- url						//	Public, Path OSC du message
		- typetag					//	Public, Typetag OSC du message
		- args						//	Public, Arguments OSC du message
		- _parse_tag				//	Prive, Table de correspondance typetag : _readType
		- _intsize					//	Prive, Taille standard d'un int (4)
		- _floatsize				//	Prive, Taille standard d'un float (4)
		- _doublesize				//	Prive, Taille standard d'un double (8)
		- _timesize					//	Prive, Taille standard d'un timetag (16?)

	Method:
		- _init_parser				//	Prive, Initialise la table de correspondance
		- _readint					//	Prive, Extrait un int de la trame OSC, retourne le debut du prochain bloc
		- _readfloat				//	Prive, Extrait un float de la trame OSC, retourne le debut du prochain bloc
		- _readdouble				//	Prive, Extrait un double de la trame OSC, retourne le debut du prochain bloc
		- _readtimetag				//	Prive, Extrait un timetag de la trame OSC, retourne le debut du prochain bloc
		- _readstring				//	Prive, Extrait une chaine de la trame OSC, retourne le debut du prochain bloc
		- _readblob					//	Prive, Extrait un blob de la trame OSC, retourne le debut du prochain bloc
		- _get_next_bloc_index		//	Prive, Arrondie au multiple de 4 superieur le plus proche, la taille passe en parametre

OscUrl : Osc
	Attribute:
		- url						//	Public, Path OSC du message

	Method:

OscError : Exception
