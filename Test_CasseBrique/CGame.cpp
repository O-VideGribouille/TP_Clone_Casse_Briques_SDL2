#include "CGame.h"
#include "CTextureManager.h"
#include "CGameObject.h"
//#include "CPlayer.h"


using namespace std;



CGame::CGame()
{
	this->m_pWindow = 0;
	this->m_pRenderer = 0;

	this->m_CurrentFrame = 0; // pour l'animation d'un sprite
	//this->m_textureManager = 0;

	//this->m_player = nullptr;


	


	this->m_bRunning = true;
}

CGame::CGame(SDL_Window* m_pWindow, SDL_Renderer* m_pRenderer, int m_CurrentFrame, bool m_bRunning)
{
	this->m_pWindow = m_pWindow;
	this->m_pRenderer = m_pRenderer;

	this->m_CurrentFrame = m_CurrentFrame;

	this->m_bRunning = m_bRunning;

	//this->m_player = nullptr;
}


CGame ::~CGame()
{
}



//INITIALISATION
bool CGame::init(const char* chr_title, int n_x, int n_y, int n_h, int n_w, int n_flags) {

	//Initialisation SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "SDl Init Succes \n";

		//Inititalisation de la fenetre;
		m_pWindow = SDL_CreateWindow(chr_title, n_x, n_y, n_w, n_h, n_flags);

		if (m_pWindow != 0) { //Créer car Init Successs

			cout << "window creation success\n";

			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0) {
				cout << "renderer creation success\n";

				//Couleur Background
				SDL_SetRenderDrawColor(m_pRenderer, 0, 27, 27, 27);
				
				//Integration du sprite du joueur
				m_textureManager.load("./Sprite/Joueur.bmp", "Joueur", m_pRenderer);

				m_player.setX(350);
				m_player.setY(590);
				m_player.setW(102);
				m_player.setH(22);

				m_player.setState(eState::IDLE);

				//Integration de la balle
				m_textureManager.load("./Sprite/balle.bmp", "Balle", m_pRenderer);

				m_ball.setX(390);
				m_ball.setY(500);
				m_ball.setW(22);
				m_ball.setH(22);

				m_ball.setspeedX(5.0f);
				m_ball.setspeedY(5.0f);

				//Integration des briques
				m_textureManager.load("./Sprite/Brique1.bmp", "Brique", m_pRenderer);
				
				for (int i = 0; i < T_H; i++) {
					for (int j = 0; j < T_W; j++) {
						
						m_bricks[i][j].setH(22);
						m_bricks[i][j].setW(780 / T_W);
						m_bricks[i][j].setY(i * 22);
						m_bricks[i][j].setX(j * (780 / T_W)  );

						m_bricks[i][j].setcasse(false);
					}
				}

				//Texte Restart
				m_textureManager.load("./Sprite/strgReplay.bmp", "Restart", m_pRenderer);
				m_text1.setX(150);
				m_text1.setY(250);
				m_text1.setW(0);
				m_text1.setH(0);


				m_textureManager.load("./Sprite/touch.bmp", "Touch", m_pRenderer);
				m_text2.setX(500);
				m_text2.setY(250);
				m_text2.setW(0);
				m_text2.setH(0);


				m_textureManager.load("./Sprite/R.bmp", "R", m_pRenderer);
				m_text3.setX(500);
				m_text3.setY(300);
				m_text3.setW(0);
				m_text3.setH(0);


				m_textureManager.load("./Sprite/button.bmp", "Button", m_pRenderer);
				m_text4.setX(500);
				m_text4.setY(350);
				m_text4.setW(0);
				m_text4.setH(0);
				
			}
			else
			{
				cout << "renderer init fail\n";
				return false; // L'inititalisation à échoué
			}
		}
		else
		{
			cout << "window init fail\n";
			return false; // Echec Init de la fenetre
		}
	}

	else
	{
		cout << "SDL init fail\n";
		return false; //Echec initialisation SDL
	}


	cout << "init success\n";
	m_bRunning = true; // Tout est ok et s'initialise


	return true;
}


//HANDLEEVENT
void CGame::handleEvents()
{

	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_RIGHT: m_player.setState(eState::RIGHT);

				break;

			case SDLK_LEFT: m_player.setState(eState::LEFT);

				break;
				case SDLK_r:  SDL_RenderClear(m_pRenderer); // Efface l'écran et les couleur disposées;
						
						//Integration du sprite du joueur
				//m_textureManager.load("./Sprite/Joueur.bmp", "Joueur", m_pRenderer);

				m_player.setX(350);
				m_player.setY(590);
				m_player.setW(102);
				m_player.setH(22);

				m_player.setState(eState::IDLE);

				//Integration de la balle
				//m_textureManager.load("./Sprite/balle.bmp", "Balle", m_pRenderer);

				m_ball.setX(390);
				m_ball.setY(500);
				m_ball.setW(22);
				m_ball.setH(22);

				m_ball.setspeedX(5.0f);
				m_ball.setspeedY(5.0f);

				//Integration des briques
				//m_textureManager.load("./Sprite/Brique1.bmp", "Brique", m_pRenderer);

				for (int i = 0; i < T_H; i++) {
					for (int j = 0; j < T_W; j++) {

						m_bricks[i][j].setH(22);
						m_bricks[i][j].setW(780 / T_W);
						m_bricks[i][j].setY(i * 22);
						m_bricks[i][j].setX(j * (780 / T_W));

						m_bricks[i][j].setcasse(false);
					}
				}

				//texte Restart
				m_text1.setW(0);
				m_text1.setH(0);


				m_text2.setW(0);
				m_text2.setH(0);

				m_text3.setW(0);
				m_text3.setH(0);

				m_text4.setW(0);
				m_text4.setH(0);

					break;

			default:
				break;
			}
			break;

		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_RIGHT:
			case SDLK_LEFT: m_player.setState(eState::IDLE);
				break;
			default:
				break;
			}

			break;

		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}



//UPDATE
void CGame::update()
{

	m_CurrentFrame = int(((SDL_GetTicks() / 100) % 6)); // animation Sprite

	//déplacement joueur

	if (m_player.getState() == eState::RIGHT) {
		m_player.setX(m_player.getX() + 10);
		//cout << "Player Right";
	}
	else if (m_player.getState() == eState::LEFT) {
		m_player.setX(m_player.getX() - 10);
	}


	//Collision 
	//Joueur contre Parois - éviter le hors écran
	if (m_player.getX() < 0) {
		m_player.setX(0);
	}
	else if (m_player.getX() > 700 - m_player.getH()) {
		m_player.setX(700 - m_player.getH());
	}

	//Déplacement Balle
	m_ball.DplcmntB();


	m_ball.setX(m_ball.getX() + m_ball.getspeedX());
	m_ball.setY(m_ball.getY() + m_ball.getspeedY());

	//Collision
	//Balle contre Parois
	//haut
	if (m_ball.getY() <= 0.0f) {
		m_ball.setY(0.0f);
		m_ball.setspeedY(m_ball.getspeedY() * -1.0f);


	}

	//bas
	if (m_ball.getY() >= 640.0f - m_ball.getH()) {

		//SDL_RenderClear(m_pRenderer); // Efface l'écran et les couleur disposées;

		m_ball.setY(640.0f - m_ball.getH());
		//m_ball.setspeedY(m_ball.getspeedY() * -1.0f);

		//Appa texte Restart
		m_text1.setW(320);
		m_text1.setH(130);


		m_text2.setW(180);
		m_text2.setH(32);

		m_text3.setW(180);
		m_text3.setH(32);

		m_text4.setW(180);
		m_text4.setH(32);

	}

	//droite
	if (m_ball.getX() >= 780.0f - m_ball.getW()) {
		m_ball.setX(780.0f - m_ball.getW());
		m_ball.setspeedX(m_ball.getspeedX() * -1.0f);
	}

	//gauche
	if (m_ball.getX() <= 0.0f) {
		m_ball.setX(0.0f);
		m_ball.setspeedX(m_ball.getspeedX() * -1.0f);
	}

	//Balle contre Joueur
	if (m_ball.getX() + m_ball.getW() >= m_player.getX()
		&& m_ball.getX() + m_ball.getW() < m_player.getX() + m_player.getW()
		&& m_ball.getY() + m_ball.getH() >= m_player.getY()
		&& m_ball.getY() + m_ball.getH() < m_player.getY() + m_player.getH()
		) {

		//m_ball.setY(m_player.getY() - m_ball.getW());

		m_ball.setspeedY(m_ball.getspeedY() * -1.01f);
	}

	//Balle contre Briques
	for (int i = 0; i < T_H; i++) {
		for (int j = 0; j < T_W; j++) {

			if (m_bricks[i][j].getcasse() == false) {
				//dessous de la brique
				if (m_ball.getX() + m_ball.getW() / 2 >= m_bricks[i][j].getX()
					&& m_ball.getX() + m_ball.getW() <= m_bricks[i][j].getX() + m_bricks[i][j].getW()
					&& m_ball.getY() >= m_bricks[i][j].getY() + m_bricks[i][j].getH() / 10
					&& m_ball.getY() <= m_bricks[i][j].getY() + m_bricks[i][j].getH())
				{

					m_ball.setspeedY(m_ball.getspeedY() * -1.01f);

					m_bricks[i][j].setcasse(true);

				}
				//côté gauche de la brique 
				if (m_ball.getX() + m_ball.getW() >= m_bricks[i][j].getX()
					&& m_ball.getX() + m_ball.getW() < m_bricks[i][j].getX() + m_bricks[i][j].getW() / 10
					&& m_ball.getY() + m_ball.getH() / 2 >= m_bricks[i][j].getY()
					&& m_ball.getY() + m_ball.getH() / 2 < m_bricks[i][j].getY() + m_bricks[i][j].getH()
					) {

					m_ball.setspeedX(m_ball.getspeedX() * -1.01f);

					m_bricks[i][j].setcasse(true);

				}
				//côté droit de la brique
				if (m_ball.getX() >= m_bricks[i][j].getX() + m_bricks[i][j].getW() - m_bricks[i][j].getW() / 10
					&& m_ball.getX() < m_bricks[i][j].getX() + m_bricks[i][j].getW()
					&& m_ball.getY() + m_ball.getH() / 2 >= m_bricks[i][j].getY()
					&& m_ball.getY() + m_ball.getH() / 2 < m_bricks[i][j].getY() + m_bricks[i][j].getH()) {

					m_ball.setspeedX(m_ball.getspeedX() * -1.01f);

					m_bricks[i][j].setcasse(true);

				}

				//dessus de la brique
				if (m_ball.getX() >= m_bricks[i][j].getX() + m_bricks[i][j].getW() - m_bricks[i][j].getW()
					&& m_ball.getX() <= m_bricks[i][j].getX() + m_bricks[i][j].getW()
					&& m_ball.getY() >= m_bricks[i][j].getY() + m_bricks[i][j].getH()
					&& m_ball.getY() <= m_bricks[i][j].getY() + m_bricks[i][j].getH() / 10) // 
				{

					m_ball.setspeedY(m_ball.getspeedY() * -1.01f);

					m_bricks[i][j].setcasse(true);

				}

			}

		}

	}

}



//AFFICHAGE
void CGame::render()
{
	SDL_RenderClear(m_pRenderer); //Effacer le Render DRAW COLORS

	//render Joueur
	m_textureManager.draw("Joueur", m_player.getX(), m_player.getY(), m_player.getW(), m_player.getH(), m_pRenderer);
	
	//render Balle
	m_textureManager.draw("Balle", m_ball.getX(), m_ball.getY(), m_ball.getW(), m_ball.getH(), m_pRenderer);
	
	//render Briques
	for (int i = 0; i < T_H; i++) {
		for (int j = 0; j < T_W; j++) {

			if (m_bricks[i][j].getcasse() == false) {
				m_textureManager.draw("Brique", m_bricks[i][j].getX(), m_bricks[i][j].getY(), m_bricks[i][j].getW(), m_bricks[i][j].getH(), m_pRenderer);
			}

		}
	}

	
	//texture restart page
	m_textureManager.draw("Restart", m_text1.getX(), m_text1.getY(), m_text1.getW(), m_text1.getH(), m_pRenderer);
	m_textureManager.draw("Touch", m_text2.getX(), m_text2.getY(), m_text2.getW(), m_text2.getH(), m_pRenderer);
	m_textureManager.draw("R", m_text3.getX(), m_text3.getY(), m_text3.getW(), m_text3.getH(), m_pRenderer);
	m_textureManager.draw("Button", m_text4.getX(), m_text4.getY(), m_text4.getW(), m_text4.getH(), m_pRenderer);





	SDL_RenderPresent(m_pRenderer); // Met en place les dessins sur l'écran

}





//LIBERATION MEMOIRE
void CGame::clean()
{

	cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow); // Détruit la fenêtre
	SDL_DestroyRenderer(m_pRenderer); // Détruit le Renderer
	SDL_Quit();

}
