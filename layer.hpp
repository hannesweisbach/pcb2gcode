/*!\defgroup LAYER*/
/******************************************************************************/
/*!
 \file       layer.hpp
 \brief

 \version
 03.08.2013 - Erik Schuster - erik@muenchen-ist-toll.de\n
 - Started documenting the code for doxygen processing.
 - Formatted the code with the Eclipse code styler (Style: K&R).

 \ingroup    LAYER
 */
/******************************************************************************/

#ifndef LAYER_H
#define LAYER_H

#include <string>
using std::string;
#include <vector>
using std::vector;

#include <boost/noncopyable.hpp>

#include "coord.hpp"
#include "surface.hpp"
#include "mill.hpp"

/******************************************************************************/
/*
 */
/******************************************************************************/
class Layer: boost::noncopyable {
public:
	Layer(const string& name, shared_ptr<Surface> surface,
			shared_ptr<RoutingMill> manufacturer, bool backside,
			bool mirror_absolute);

	vector<shared_ptr<icoords> > get_toolpaths();
	shared_ptr<RoutingMill> get_manufacturer();
	vector<unsigned int> get_bridges( shared_ptr<icoords> toolpath );
	string get_name() {
		return name;
	}
	;
	void add_mask(shared_ptr<Layer>);

private:
	string name;
	bool mirrored;
	bool mirror_absolute;
	shared_ptr<Surface> surface;
	shared_ptr<RoutingMill> manufacturer;

	friend class Board;
};

#endif // LAYER_H
