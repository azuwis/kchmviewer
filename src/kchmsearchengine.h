/***************************************************************************
 *   Copyright (C) 2004-2007 by Georgy Yunaev, gyunaev@ulduzsoft.com       *
 *   Please do not use email address above for bug reports; see            *
 *   the README file                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/

#ifndef KCHMSEARCHENGINE_H
#define KCHMSEARCHENGINE_H

#include "kde-qt.h"
#include "libchmfile.h"

namespace QtAs { class Index; };


class KCHMSearchEngine : public QObject
{
	Q_OBJECT
			
	public:
		KCHMSearchEngine();
		~KCHMSearchEngine();
		
		bool	loadOrGenerateIndex();
		bool	searchQuery ( const QString& query, QStringList * results, unsigned int limit = 100 );
		
		
	private slots:
		void	setIndexingProgress( int progress );
		void	cancelButtonPressed();

	private:
		void	processEvents();

		// Used during the index generation
		QProgressDialog			*	m_progressDlg;
		QStringList 				m_keywordDocuments;
		QtAs::Index 			*	m_Index;
};

#endif
